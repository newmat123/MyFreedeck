# MyFreedeck

## Description

This is my take on the well-known freedeck-ino (https://github.com/FreeYourStream/freedeck-ino), but not as advanced. You must create the bitmap images for the screens yourself
and place them manually in the code. When a screen is pressed, the arduino sends a predetermined shortcut combination that can be used to open programs or otherwise interact with the computer.

## Shourtcuts
1. CTRL + ALT + O
2. CTRL + ALT + P
3. CTRL + ALT + L
4. CTRL + ALT + J
5. CTRL + ALT + H
6. CTRL + ALT + Y

How to create the shourtcuts on the pc:
https://www.youtube.com/watch?v=Oh1EkSBveIQ

Image converter to bitmap:
https://javl.github.io/image2cpp/

Canvas size(s): 128 x 64 <br>
Background color: black <br>
Invert image colors: true <br>

## Hardware used
- Perfboard
- Arduino Pro Micro (32u4 16mhz 5v)
- 2x 4051 Multiplexer
- 6x ssd1306 OLEDs
- 6x 6x4x4mm buttons

## Schematic
![The schematic](https://github.com/newmat123/MyFreedeck/blob/main/schematics.png?raw=true)

## Finished product
![The finished product](https://github.com/newmat123/MyFreedeck/blob/main/product.jpg?raw=true)