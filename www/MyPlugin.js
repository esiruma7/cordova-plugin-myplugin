var exec = require('cordova/exec');

var MyPlugin = {
    /**
     * Simple Hello World test
     * Usage:
     *   window.MyPlugin.sayHello("World",
     *       function(res) { alert("OK: " + res); },
     *       function(err) { alert("ERR: " + err); });
     */
    sayHello: function (name, success, error) {
        exec(success, error, "MyPlugin", "sayHello", [name]);
    },

    /**
     * Test whether LEGIC SDK classes are accessible
     * Usage:
     *   window.MyPlugin.testLegic(
     *       function(res) { alert("OK: " + res); },
     *       function(err) { alert("ERR: " + err); });
     */
    testLegic: function (success, error) {
        exec(success, error, "MyPlugin", "testLegic", []);
    },

    /**
     * Initialize LEGIC SDK (if available)
     * Usage:
     *   window.MyPlugin.initLegic(appId, user, pass, url,
     *       function(res) { alert("OK: " + res); },
     *       function(err) { alert("ERR: " + err); });
     */
    initLegic: function (appId, user, pass, url, success, error) {
        exec(success, error, "MyPlugin", "initLegic", [appId, user, pass, url]);
    }
};

window.MyPlugin = MyPlugin;   // <--- force attach to window
module.exports = MyPlugin;
