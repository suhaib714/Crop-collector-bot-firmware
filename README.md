# Crop-collector-bot-firmware

# Crop Collector Bot (ESP32 Firmware)

Firmware for an ESP32 crop collecting robot. It is driven manually from a phone over Bluetooth, and a front paddle/brush sweeps the crop in.

## How it works

**Manual control.** The bot is controlled from a phone using the Dabble Gamepad app. The ESP32 appears as `G's Crop Bot`, and the loop reads the gamepad continuously and acts on one button at a time:
- Up / Down: both drive motors run forward / backward
- Left / Right: the two sides run in opposite directions, so the bot turns on the spot
- Triangle: runs the front paddle/brush
- No button pressed: every motor stops

**Drive motors.** Two motors, one for each side, are controlled through a motor driver (ENA/IN1/IN2 and ENB/IN3/IN4). The enable pins are set HIGH at startup, so the motors always run at full speed. Direction is set by the two input pins of each motor: HIGH/LOW runs it one way, LOW/HIGH the other way, and LOW/LOW stops it.

**Front paddle/brush.** A second motor driver (JNA/JN3/JN4 and JNB/JN1/JN2) controls the paddle motors. They run only while Triangle is held and stop as soon as it is released.
