package com.ofe.myplugin;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

// Import LEGIC classes from the JAR
import com.legic.mobile.sdk.LegicMobileSdk;
import com.legic.mobile.sdk.LegicMobileSdkConfiguration;

public class MyPlugin extends CordovaPlugin {

    private LegicMobileSdk legicSdk;

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if ("initLegic".equals(action)) {
            initLegic(callbackContext);
            return true;
        }
        return false;
    }

    private void initLegic(CallbackContext callbackContext) {
        try {
            // Initialize the SDK with a default configuration
            LegicMobileSdkConfiguration config =
                new LegicMobileSdkConfiguration.Builder().build();

            legicSdk = LegicMobileSdk.getInstance(
                cordova.getContext(),
                config
            );

            if (legicSdk != null) {
                callbackContext.success("LEGIC SDK initialized successfully!");
            } else {
                callbackContext.error("LEGIC SDK initialization returned null");
            }

        } catch (Exception e) {
            callbackContext.error("LEGIC SDK init failed: " + e.getMessage());
        }
    }
}
