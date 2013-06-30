It's a work-in-progress library to create a digital clock/timer using a ILI9225G lcd and a generic DS1302 rtc module.
The code depends on the ILI9225 library and DS1302 library from [MATT SPARKS](https://github.com/msparks/arduino-ds1302)

The library is very specific to the project and so is the ILI9225 library but I will be trying to make it more generic in the future.
Documentation in the source is not at all usefull but again I will be targetting that once I feel comfortable with the state of the library.

Problems with the current code:
The font used is not good for the graphics the lcd is capable of and should be changed.
The full clear screen is slow so I want to find a better way to do that.
The LCD library hardcodes Vertical orientation.(Some changes should make it horizontal though)
