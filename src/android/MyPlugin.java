package com.ofe.myplugin;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.json.JSONArray;
import org.json.JSONException;

public class MyPlugin extends CordovaPlugin {

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if ("sayHello".equals(action)) {
            String name = args.getString(0);
            this.sayHello(name, callbackContext);
            return true;
        }
        return false; // triggers "Invalid Action" if not sayHello
    }

    private void sayHello(String name, CallbackContext callbackContext) {
        if (name != null && name.length() > 0) {
            callbackContext.success("Hello, " + name);
        } else {
            callbackContext.error("Expected a non-empty string argument.");
        }
    }
}
