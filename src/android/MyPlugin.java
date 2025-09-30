package com.ofe.myplugin;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;

// LEGIC imports (kept)
import com.legic.mobile.sdk.api.LegicMobileSdkManager;
import com.legic.mobile.sdk.api.LegicMobileSdkManagerFactory;
import com.legic.mobile.sdk.api.LegicMobileSdkConfiguration;

public class MyPlugin extends CordovaPlugin {

    private LegicMobileSdkManager legicManager;

    @Override
    protected void pluginInitialize() {
        try {
            String initKey = "INIT_KEY_HERE"; // 🔑 Replace later when available

            LegicMobileSdkConfiguration config =
                new LegicMobileSdkConfiguration.Builder(initKey).build();

            legicManager = LegicMobileSdkManagerFactory.getInstance().create(config);

            android.util.Log.i("MyPlugin", "LEGIC SDK initialized (hello test mode) ✅");
        } catch (Exception e) {
            android.util.Log.e("MyPlugin", "LEGIC init failed: " + e.getMessage(), e);
        }
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if ("sayHello".equals(action)) {
            String name = args.getString(0);
            this.sayHello(name, callbackContext);
            return true;
        }
        return false; // any other action → "Invalid Action"
    }

    private void sayHello(String name, CallbackContext callbackContext) {
        if (name != null && name.length() > 0) {
            callbackContext.success("Hello, " + name);
        } else {
            callbackContext.error("Expected a non-empty string argument.");
        }
    }
}
