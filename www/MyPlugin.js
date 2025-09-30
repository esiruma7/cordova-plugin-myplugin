var exec = require('cordova/exec');

module.exports = {
  sayHello: function (name, ok, err) { exec(ok, err, "MyPlugin", "sayHello", [name]); },
  testLegic: function (ok, err) { exec(ok, err, "MyPlugin", "testLegic", []); },
  // initLegic(appId:number, techUser:string, techPass:string, lcUrl:string)
  initLegic: function (appId, user, pass, url, ok, err) {
    exec(ok, err, "MyPlugin", "initLegic", [appId, user, pass, url]);
  }
};
