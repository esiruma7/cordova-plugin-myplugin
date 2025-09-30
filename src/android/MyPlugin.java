package com.ofe.myplugin;

import android.util.Log;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.json.JSONArray;
import org.json.JSONException;

public class MyPlugin extends CordovaPlugin {
    private static final String TAG = "MyPlugin";

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext cb) throws JSONException {
        switch (action) {
            case "sayHello":
                return sayHello(args, cb);

            case "testLegic":
                return testLegic(cb);

            case "initLegic":
                return initLegic(args, cb);

            default:
                return false; // Invalid action
        }
    }

    private boolean sayHello(JSONArray args, CallbackContext cb) {
        String name = args.optString(0, "World");
        cb.success("Hello, " + name);
        return true;
    }

    private boolean testLegic(CallbackContext cb) {
        try {
            Class.forName("com.legic.mobile.sdk.api.LegicMobileSdkManager");
            cb.success("LEGIC Manager interface found ✅");
        } catch (ClassNotFoundException e) {
            cb.success("LEGIC classes NOT found on classpath ❌");
        }
        return true;
    }

    private boolean initLegic(JSONArray args, CallbackContext cb) {
        try {
            // Stubbed response for now
            cb.success("LEGIC init stub (Android)");
            return true;
        } catch (Throwable t) {
            Log.e(TAG, "LEGIC init error", t);
            cb.error("LEGIC init error: " + t.getMessage());
            return true;
        }
    }
}
