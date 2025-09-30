package com.ofe.myplugin;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

// ✅ Correct LEGIC API imports
import com.legic.mobile.sdk.api.LegicMobileSdkManager;
import com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory;
import com.legic.mobile.sdk.api.exception.SdkException;
import com.legic.mobile.sdk.api.types.SdkStatus;

public class MyPlugin extends CordovaPlugin {

    private LegicMobileSdkManager legicManager;

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if ("sayHello".equals(action)) {
            String message = args.getString(0);
            this.sayHello(message, callbackContext);
            return true;
        } else if ("initLegic".equals(action)) {
            this.initLegic(callbackContext);
            return true;
        }
        return false; // Invalid action
    }

    private void sayHello(String message, CallbackContext callbackContext) {
        if (message != null && message.length() > 0) {
            callbackContext.success("Hello, " + message);
        } else {
            callbackContext.error("Expected one non-empty string argument.");
        }
    }

    private void initLegic(CallbackContext callbackContext) {
        try {
            // ⚠️ This requires a valid init key (will fail with Invalid Key for now)
            legicManager = LegicMobileSdkManagerFactory.create(
                cordova.getContext().getApplicationContext()
            );

            if (legicManager != null) {
                SdkStatus status = legicManager.getSdkStatus();
                callbackContext.success("LEGIC SDK initialized, status: " + status);
            } else {
                callbackContext.error("LEGIC SDK Manager not available");
            }
        } catch (SdkException e) {
            callbackContext.error("LEGIC SDK init failed: " + e.getMessage());
        } catch (Exception e) {
            callbackContext.error("Unexpected error: " + e.getMessage());
        }
    }
}
