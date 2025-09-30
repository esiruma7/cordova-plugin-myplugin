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
			// If you have a real SDK, try to init it here
			// For now, just stub to confirm the bridge works
			cb.success("LEGIC init stub (Android)");
			return true;
		} catch (Throwable t) {
			cb.error("LEGIC init error: " + t.getMessage());
			return true;
		}
	}