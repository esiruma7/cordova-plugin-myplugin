package com.ofe.myplugin;

import org.apache.cordova.*;
import org.json.JSONArray;
import org.json.JSONException;

// Import from LEGIC SDK JAR
import com.legic.mobile.sdk.LegicMobileSdk;
import com.legic.mobile.sdk.LegicMobileSdkConfiguration;

public class MyPlugin extends CordovaPlugin {
    private LegicMobileSdk legicSdk;

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if ("initLegic".equals(action)) {
            // Initialize SDK
            legicSdk = LegicMobileSdk.getInstance(
                cordova.getContext(),
                new LegicMobileSdkConfiguration.Builder().build()
            );
            callbackContext.success("LEGIC SDK initialized");
            return true;
        }
        return false;
    }
}
