#include "Keyboard.h"
#include "bitmaps.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// On an arduino LEONARDO:   2(SDA),  3(SCL),

const int screens = 6;
const int delayTime = 250; //250 ms
const char ShortCut[screens] = {'o','p','l','j','h','y'};
int previousButtonState[screens] = {HIGH};  // for checking the state of a pushButton

//link to modifyer keys
//https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/
const char ctrlKey = KEY_LEFT_CTRL; 
const char altKey = KEY_LEFT_ALT;

const int btnReadPin = 6;

void setup() {
  //button read pin
  pinMode(btnReadPin,INPUT);
  DDRB = 0b0001110;  //PORT 8,9,10 as output
  PORTB = 0b0000000; //PORT 8,9,10 set to LOW
  
  for (int i = 0; i < screens; i++) {
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
      //Serial.println(F("SSD1306 allocation failed"));
      for(;;);
    }
    display.clearDisplay();

    if (i <= bitmap_allArray_LEN){
      display.drawBitmap(0, 0,  bitmap_allArray[i], 128, 64, WHITE);
      display.display();
    }else{
      //typecasting shortCut to string
      draw(String(ShortCut[i]));
    }
    PORTB = PORTB + 2;
  }
  Keyboard.begin();
}

void draw(String text){
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  // Display static text
  display.println(text);
  display.display();
}

void loop() {
  PORTB = 0b0000000;
  for (int i = 0; i < screens; i++) {
    // read the pushbutton:
    int buttonState = digitalRead(btnReadPin);
    // if the button state has changed,
    if ((buttonState != previousButtonState[i]) && (buttonState == HIGH)) {
      
      Keyboard.press(altKey);
      Keyboard.press(ctrlKey);
      Keyboard.press(ShortCut[i]);
      Keyboard.releaseAll();
      delay(delayTime);
    }
    // save the current button state for comparison next time:
    previousButtonState[i] = buttonState;
    PORTB = PORTB + 2;
  }
}
