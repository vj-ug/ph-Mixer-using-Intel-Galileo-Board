# ph Mixer using Intel Galileo Gen 2

- AT&T Hackathon Runner's Up

Software:
-	Arduino sketch to control pumps and send sensor data to cloud
-	Cloud Logic to control mixing
-	Browser page to start/stop mixing & time process

Hardware:
-	Circuit to interface Galileo to pumps and sensors
-	Warning: Galileo power is 12V pumps are 6V
-	Pumps draw 300ma Galileo output pins supply 20ma

Ambient Light sensor is used for threshold


The [Intel Galileo Gen 2](https://www-ssl.intel.com/content/www/us/en/do-it-yourself/galileo-maker-quark-board.html) has a pin-out form similar to an Arduino Uno. 

[![](https://cdn.sparkfun.com//assets/parts/1/0/1/3/8/13096-01.jpg)](https://cdn.sparkfun.com//assets/parts/1/0/1/3/8/13096-01.jpg)

Example: 

```js
var start = require("vj");
var Galileo = require("galileo-io");
var board = new five.Board({
  io: new Galileo()
});

board.on("ready", function() {
  var led = new five.Led(13);
  led.blink(500);
});
```

