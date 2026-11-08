# Cosmotyl ZMK configuration

## RGB underglow state after idle

This configuration enables `CONFIG_ZMK_RGB_UNDERGLOW_AUTO_OFF_IDLE` to turn
the underglow off while idle. ZMK currently saves this automatic off state as
if RGB had been manually turned off. On the next restart, that saved state can
override the startup default and leave the LEDs off.

The upstream fix is tracked in [zmkfirmware/zmk#3463](https://github.com/zmkfirmware/zmk/pull/3463),
which changes automatic idle and USB on/off transitions so they do not overwrite
the user's saved RGB state. The PR must be merged and included in this config's
pinned ZMK revision to resolve the issue.

Until then, use `RGB_ON` on the system layer's R key to turn the underglow back
on.
