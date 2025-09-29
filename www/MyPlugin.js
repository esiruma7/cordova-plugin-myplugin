var exec = require('cordova/exec');

exports.sayHello = function (message, success, error) {
    exec(success, error, "MyPlugin", "sayHello", [message]);
};
