package com.ofe.myplugin;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

// LEGIC SDK imports
import com.legic.mobile.sdk.LegicMobileSdkManager;
import com.legic.mobile.sdk.LegicMobileSdkManagerFactory;

public class MyPlugin extends CordovaPlugin {

    private LegicMobileSdkManager sdkManager;

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
            // Get SDK manager instance
            sdkManager = LegicMobileSdkManagerFactory.getInstance().getManager();

            if (sdkManager != null) {
                // Note: real initialization requires AppID, tech user, password, and LEGIC Connect URL
                // That comes from your LEGIC account / provisioning
                // Example: sdkManager.start(appContext, appId, techUser, techPassword, connectUrl);

                callbackContext.success("LEGIC SDK Manager available!");
            } else {
                callbackContext.error("LEGIC SDK Manager is null.");
            }

        } catch (Exception e) {
            callbackContext.error("LEGIC init failed: " + e.getMessage());
        }
    }
}
