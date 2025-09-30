var exec = require('cordova/exec');

var MyPlugin = {
    sayHello: function (name, success, error) {
        exec(success, error, "MyPlugin", "sayHello", [name]);
    }
};

module.exports = MyPlugin;
