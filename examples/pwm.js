// Example of using PWM
var wpi = require('wiring-pi');
var async = require('async');

wpi.setup();

var pin = 1;
wpi.pinMode(pin, wpi.modes.PWM_OUTPUT);

async.series([
  function (cb) {
    wpi.pwmWrite(pin, 100);
    cb();
  },
  function (cb) {
    setTimeout(cb, 1000);
  },
  function (cb) {
    wpi.pwmWrite(pin, 1023);
    cb();
  },
  function (cb) {
    setTimeout(cb, 1000);
  },
  function (cb) {
    wpi.pwmWrite(pin, 0);
    cb();
  }
], function (err) {
});
