# ofxRpiLED

OpenFrameworks LED matrix addon for Raspberry Pi. It is recommended to install an image with a realtime kernel
(for instance [this one][emlid-rt]) to minimize a loaded system having an influence on the image quality.


**Hardware**

- Raspberry PI Model B / 2
- [Adafruit LED Hat][ada-hat]

**LED Library**

The addon uses hzeller's [LED library][led-lib] precompiled. Probably you'll need to recompile the library if you are using a different hardware setup.

The LED library is precompiled with the following configuration options:

```
# Uncomment the following line for Adafruit Matrix HAT gpio mappings.
# If you have an Adafruit HAT ( https://www.adafruit.com/products/2345 ),
# you need to use this option as the HAT swaps pins around that are not
# compatible with the default mapping.
DEFINES+=-DADAFRUIT_RGBMATRIX_HAT

# Uncomment if you want to use the Adafruit HAT with stable PWM timings
# The newer version of this library allows for much more stable (less flicker)
# output, but it does not work with the Adafruit HAT unless you do a
# simple hardware hack on them: connectk GPIO 4 (OE) with 18; they have
# convenient solder holes on the board.
# Then uncomment the following define.
DEFINES+=-DADAFRUIT_RGBMATRIX_HAT_PWM
```

[ada-hat]: https://www.adafruit.com/products/2345/
[led-lib]: https://github.com/hzeller/rpi-rgb-led-matrix/
[emlid-rt]: http://docs.emlid.com/Downloads/Real-time-Linux-RPi2/
