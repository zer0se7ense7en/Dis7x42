# 7x42 LED-Display
## A nerdy way of displaying text

The main goal of this project was to make a Display using the WS2812B LED Strips. The Project is hosted on GitHub. An Arduino controls the LED-Strips and displays a predefined string of chars. It is powered by a Step-Up, which is powered by the Power Supply, which also powers the LED-Strips.

### Hardware:
- Arduino Mega (Functions as a LED-Controller)
- 7x42 LEDs of type WS2812B (The pixels in the display)
- 10A 5V Power Supply (Provides power to the Step-Up and the LEDs)
- Step-Up Converter (Provides the Arduino Mega with ~9-12V)
- some Jumper Wires, WAGO-Klemmen, and thiccer Cabels
- a lot of cable ties (to hold the LED-Strip on to the wood)
- a wooden Plate
- a Macrolon Plate
- some custom-made 3D-printed Mounts (to hold everything together)
- some M4-Screws and Nuts (to screw the Mounts)

### Software:
- about 1000 lines of Arduino-Code(mostly C++)
- the FastLED-Library as a Framework for the Arduino-LED Communication on Hardware-Level
- mostly self-written Code to define digit & character layouts, organize scrolling, input, etc.
