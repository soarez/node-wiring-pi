var wpi = require('../lib/exports');

wpi.setup();

var pin = 0;

wpi.pinMode(0, wpi.modes.OUTPUT);

var value = 1;

setInterval(function() {
  wpi.digitalWrite(pin, value);
  value = +!value;
}, 500);
