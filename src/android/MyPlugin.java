package com.ofe.myplugin;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;

// LEGIC API imports
import com.legic.mobile.sdk.api.LegicMobileSdkManager;
import com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory;
import com.legic.mobile.sdk.api.LegicMobileSdkConfiguration;

public class MyPlugin extends CordovaPlugin {

    private LegicMobileSdkManager legicManager;

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        switch (action) {
            case "initLegic":
                this.initLegic(callbackContext);
                return true;
            case "getVersion":
                this.getVersion(callbackContext);
                return true;
            case "isNfcAvailable":
                this.isNfcAvailable(callbackContext);
                return true;
            default:
                return false;
        }
    }

    private void initLegic(CallbackContext callbackContext) {
        try {
            // Create SDK configuration
            LegicMobileSdkConfiguration config = new LegicMobileSdkConfiguration.Builder()
                    .setDebugMode(true)   // enable debug for testing
                    .build();

            // Initialize SDK manager
            legicManager = LegicMobileSdkManagerFactory.getInstance(cordova.getContext(), config);

            if (legicManager != null) {
                callbackContext.success("LEGIC SDK initialized successfully");
            } else {
                callbackContext.error("Failed to initialize LEGIC SDK");
            }
        } catch (Exception e) {
            callbackContext.error("Exception during init: " + e.getMessage());
        }
    }

    private void getVersion(CallbackContext callbackContext) {
        try {
            if (legicManager != null) {
                String version = legicManager.getVersion();
                callbackContext.success(version);
            } else {
                callbackContext.error("LEGIC SDK not initialized");
            }
        } catch (Exception e) {
            callbackContext.error("Exception in getVersion: " + e.getMessage());
        }
    }

    private void isNfcAvailable(CallbackContext callbackContext) {
        try {
            if (legicManager != null) {
                boolean available = legicManager.isNfcAvailable();
                callbackContext.success(available ? "true" : "false");
            } else {
                callbackContext.error("LEGIC SDK not initialized");
            }
        } catch (Exception e) {
            callbackContext.error("Exception in isNfcAvailable: " + e.getMessage());
        }
    }
}
