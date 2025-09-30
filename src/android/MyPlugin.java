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
                cb.error("Invalid action: " + action);
                return false;
        }
    }

    // --- ACTION 1: Hello World ---
    private boolean sayHello(JSONArray args, CallbackContext cb) {
        try {
            String name = args.optString(0, "World");
            cb.success("Hello, " + name);
            return true;
        } catch (Exception e) {
            cb.error("sayHello error: " + e.getMessage());
            return false;
        }
    }

    // --- ACTION 2: Test LEGIC SDK classes ---
    private boolean testLegic(CallbackContext cb) {
        try {
            Class.forName("com.legic.mobile.sdk.api.LegicMobileSdkManager");
            cb.success("LEGIC Manager interface found ✅");
            return true;
        } catch (ClassNotFoundException e) {
            cb.error("LEGIC classes NOT found on classpath: " + e.getMessage());
            return true;
        }
    }

    // --- ACTION 3: Init LEGIC (Stub for now) ---
    private boolean initLegic(JSONArray args, CallbackContext cb) {
        try {
            // Stubbed until unobfuscated SDK is provided
            cb.success("LEGIC init stub (Android)");
            return true;
        } catch (Throwable t) {
            Log.e(TAG, "LEGIC init error", t);
            cb.error("LEGIC init error: " + t.getMessage());
            return true;
        }
    }
}
