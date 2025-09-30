package com.ofe.myplugin;

import android.content.Context;
import android.util.Log;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.json.JSONArray;
import org.json.JSONException;

import java.lang.reflect.Method;

public class MyPlugin extends CordovaPlugin {
    private static final String TAG = "MyPlugin";

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext cb) throws JSONException {
        switch (action) {
            case "sayHello":
                String name = args.optString(0, "World");
                cb.success("Hello, " + name);
                return true;

            case "testLegic":
                return testLegic(cb);

            case "initLegic": // initLegic(appId, user, pass, url)
                return initLegic(args, cb);
        }
        return false; // Invalid action
    }

    private boolean testLegic(CallbackContext cb) {
        try {
            Class.forName("com.legic.mobile.sdk.api.LegicMobileSdkManager");
            // Factory may or may not exist in this SDK – check presence only
            boolean hasFactory;
            try { Class.forName("com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory"); hasFactory = true; }
            catch (ClassNotFoundException e) { hasFactory = false; }
            cb.success("LEGIC Manager interface found" + (hasFactory ? " (+ Factory present)" : " (Factory not present)"));
            return true;
        } catch (ClassNotFoundException e) {
            cb.error("LEGIC classes NOT found on classpath: " + e.getMessage());
            return true;
        }
    }

    private boolean initLegic(JSONArray args, CallbackContext cb) {
        try {
            Context ctx = cordova.getActivity().getApplicationContext();

            // Try several creation patterns seen across SDK versions
            Object manager = null;

            // 1) api.LegicMobileSdkManagerFactory.create(Context)
            try {
                Class<?> fac = Class.forName("com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory");
                try {
                    Method m = fac.getMethod("create", Context.class);
                    manager = m.invoke(null, ctx);
                } catch (NoSuchMethodException ignore) { /* continue */ }
            } catch (ClassNotFoundException ignore) { /* continue */ }

            // 2) api.LegicMobileSdkManagerFactory.getInstance().create(Context)
            if (manager == null) {
                try {
                    Class<?> fac = Class.forName("com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory");
                    Method getInst = fac.getMethod("getInstance");
                    Object inst = getInst.invoke(null);
                    try {
                        Method m = fac.getMethod("create", Context.class);
                        manager = m.invoke(inst, ctx);
                    } catch (NoSuchMethodException ignore) { /* continue */ }
                } catch (ClassNotFoundException | NoSuchMethodException ignore) { /* continue */ }
            }

            if (manager == null) {
                cb.error("LEGIC Manager could not be created via known factory patterns. " +
                         "SDK 3.1.2.0 expects starting the manager and credentials via start(...).");
                return true;
            }

            // If you pass credentials, try start(long,String,String,String)
            if (args != null && args.length() >= 4) {
                long appId     = args.optLong(0, 0L);
                String user    = args.optString(1, "");
                String pass    = args.optString(2, "");
                String lcUrl   = args.optString(3, "");

                try {
                    Method start = manager.getClass().getMethod(
                            "start", long.class, String.class, String.class, String.class);
                    start.invoke(manager, appId, user, pass, lcUrl);
                    cb.success("LEGIC SDK started ✅");
                    return true;
                } catch (NoSuchMethodException nsme) {
                    // start(...) signature not found – still return success for creation
                    Log.w(TAG, "start(long,String,String,String) not found on manager");
                }
            }

            cb.success("LEGIC Manager created (not started).");
            return true;

        } catch (Throwable t) {
            cb.error("LEGIC init error: " + t.getClass().getSimpleName() + ": " + t.getMessage());
            return true;
        }
    }
}
