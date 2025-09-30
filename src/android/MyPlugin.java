package com.ofe.myplugin;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;

public class MyPlugin extends CordovaPlugin {

    @Override
    protected void pluginInitialize() {
        // Stub init: avoid referencing missing LEGIC classes
        android.util.Log.i("MyPlugin", "LEGIC SDK init stub (waiting for unobfuscated jar) ✅");
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
        return false;
    }
}
