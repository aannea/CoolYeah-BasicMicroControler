# Basic-Micro-Controler
I Learned basic micro controllers

## 001_Led.ino
The code you provided is written in Arduino programming language, and it defines a simple program to blink an LED connected to pin 9 repeatedly.
The setup() function is an Arduino-specific function that runs once when the board is powered on or reset. In this case, it configures pin 9 as an output pin using the pinMode() function. This pin will be used to control the LED.
The loop() function is another Arduino-specific function that runs repeatedly after the setup() function. In this code, it contains the logic to blink the LED connected to pin 9.
- digitalWrite(9, HIGH); sets the voltage of pin 9 to HIGH, which turns on the LED.
- delay(500); pauses the program execution for 500 milliseconds (half a second).
- digitalWrite(9, LOW); sets the voltage of pin 9 to LOW, which turns off the LED.
- delay(500); pauses the program execution for another 500 milliseconds.

This sequence of turning the LED on, waiting for 500 milliseconds, turning it off, and waiting for another 500 milliseconds is repeated indefinitely, creating the blinking effect.
Make sure you have an LED connected to pin 9 of your Arduino board for this code to work correctly.

## 002_LCD.ino
The code you provided is an Arduino sketch that utilizes the LiquidCrystal library to control an LCD (Liquid Crystal Display) module. 
The code begins by including the LiquidCrystal library, which provides functions to interface with the LCD module. The LiquidCrystal object lcd is then created, specifying the pins to which the LCD module is connected (in this case, pin 7 is for RS, pin 6 for E, pin 5 for D4, pin 4 for D5, pin 3 for D6, and pin 2 for D7).
In the setup() function, which is executed once at the start, the LCD module is initialized. The lcd.begin(16, 2) function initializes the LCD module with 16 columns and 2 rows.
Next, the cursor position is set using lcd.setCursor(column, row). In this case, lcd.setCursor(0, 0) sets the cursor to the first column of the first row. The lcd.print() function is then used to display the text "Cia, Puspita, Farhan" at that position.
Afterward, the cursor position is set to the fourth column of the second row using lcd.setCursor(4, 1), and the text "IF-09-M" is printed at that position.
The loop() function is executed repeatedly after the setup() function. In this code, it continuously scrolls the entire display one position to the left using lcd.scrollDisplayLeft(). The delay(500) function is used to introduce a 500 milliseconds delay between each scroll, creating a scrolling effect.
Overall, this code initializes the LCD module, displays some text on it, and then continuously scrolls the displayed content to the left. Make sure you have the LCD module properly connected to the specified pins for this code to work correctly.
