var exec = require("cordova/exec");

exports.initLegic = function(success, error) {
    exec(success, error, "MyPlugin", "initLegic", []);
};
