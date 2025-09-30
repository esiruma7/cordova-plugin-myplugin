package com.ofe.myplugin;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;

// LEGIC SDK imports
import com.legic.mobile.sdk.api.LegicMobileSdkManager;
import com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory;
import com.legic.mobile.sdk.api.LegicMobileSdkConfiguration;

public class MyPlugin extends CordovaPlugin {

    private LegicMobileSdkManager legicManager;

    @Override
    protected void pluginInitialize() {
        try {
            // Placeholder init key (will trigger "Invalid Key" until a real one is provided)
            String initKey = "INIT_KEY_HERE";

            LegicMobileSdkConfiguration config =
                new LegicMobileSdkConfiguration.Builder(initKey).build();

            legicManager = LegicMobileSdkManagerFactory.getInstance().create(config);

            android.util.Log.i("MyPlugin", "LEGIC SDK init attempted ✅");
        } catch (Exception e) {
            android.util.Log.e("MyPlugin", "LEGIC init failed: " + e.getMessage(), e);
        }
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if ("sayHello".equals(action)) {
            String name = args.getString(0);
            if (name != null && name.length() > 0) {
                callbackContext.success("Hello, " + name);
            } else {
                callbackContext.error("Expected a non-empty string argument.");
            }
            return true;
        }
        return false; // Cordova will throw "Invalid Action" if no match
    }
}
