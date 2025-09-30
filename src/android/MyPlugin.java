package com.ofe.myplugin;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;

// LEGIC API imports (note the .api package)
import com.legic.mobile.sdk.api.LegicMobileSdkManager;
import com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory;

public class MyPlugin extends CordovaPlugin {

    private LegicMobileSdkManager legicManager;

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if ("initLegic".equals(action)) {
            this.initLegic(callbackContext);
            return true;
        }
        return false;
    }

    private void initLegic(CallbackContext callbackContext) {
        try {
            // Initialize SDK Manager through factory
            legicManager = LegicMobileSdkManagerFactory.getInstance(cordova.getContext());

            if (legicManager != null) {
                callbackContext.success("LEGIC SDK initialized successfully");
            } else {
                callbackContext.error("Failed to initialize LEGIC SDK");
            }
        } catch (Exception e) {
            callbackContext.error("Exception: " + e.getMessage());
        }
    }
}
