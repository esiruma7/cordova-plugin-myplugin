var exec = require('cordova/exec');

module.exports = {
    sayHello: function (name, success, error) {
        exec(success, error, "MyPlugin", "sayHello", [name]);
    },
    testLegic: function (success, error) {
        exec(success, error, "MyPlugin", "testLegic", []);
    },
    initLegic: function (appId, user, pass, url, success, error) {
        exec(success, error, "MyPlugin", "initLegic", [appId, user, pass, url]);
    }
};
