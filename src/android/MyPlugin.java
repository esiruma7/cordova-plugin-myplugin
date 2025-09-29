package com.ofe.myplugin;

import org.apache.cordova.*;
import org.json.JSONArray;
import org.json.JSONException;

public class MyPlugin extends CordovaPlugin {
    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (action.equals("sayHello")) {
            String msg = args.getString(0);
            callbackContext.success("Hello from Android: " + msg);
            return true;
        }
        return false;
    }
}
