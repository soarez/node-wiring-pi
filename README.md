Node.js bindings to [wiringPi](https://projects.drogon.net/raspberry-pi/wiringpi/)

## Install

    > npm install wiring-pi

## Use

```javascript

var wpi = require('wiring-pi');

```

### `wpi.setup([mode])`

Valid Modes:

- `wpi`: sets up pin numbering with `wiringPiSetup`
- `gpio`: sets up pin numbers with `wiringPiSetupGpio`
- `sys`: sets up pin numbers with `wiringPiSetupSys`

See [wiringPi Pins](http://wiringpi.com/pins/) for the differences in Pin numbering;

### `wpi.pinMode(pin, mode)`

- `pin`: pin number
- `mode`: `wpi.INPUT`, `wpi.OUTPUT`, or `wpi.PWM_OUTPUT`

### `wpi.digitalWrite(pin, value)`

- `pin`: pin number
- `value`: 0 or 1

### `wpi.digitalRead(pin)`

- `pin`: pin number

### Wrapped WiringPI calls:

These have the same arguments as their WiringPi counterparts

- `piBoardRev`
- `pwmSetRange`
- `pwmSetClock`
- `pwmWrite`
