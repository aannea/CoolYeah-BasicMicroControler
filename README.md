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

## 003_LedButton.ino
The code is an Arduino sketch written in the C++ programming language. It uses a push-button and an LED to demonstrate digital input and output operations. When the button is pressed, the LED turns off, and when the button is released, the LED turns on.
The code declares two variables: button and led, which represent the pin numbers for the button and the LED, respectively. In the setup() function, the serial communication is initialized with a baud rate of 9600 using Serial.begin(9600). The pinMode() function is used to set the button pin as an input and the led pin as an output.
In the loop() function, the code repeatedly performs the following steps:
- It reads the state of the button by using digitalRead(button) and stores the value in the variable nilaiButton.
- It checks if the value of nilaiButton is LOW, indicating that the button is pressed. If it is LOW, it executes the code inside the if statement.
- Inside the if statement, it prints "LOW" to the serial monitor using Serial.println("LOW") and turns off the LED by setting the led pin to LOW using digitalWrite(led, LOW).
- If the value of nilaiButton is not LOW, which means the button is released, it executes the code inside the else block.
- Inside the else block, it prints "HIGH" to the serial monitor using Serial.println("HIGH") and turns on the LED by setting the led pin to HIGH using digitalWrite(led, HIGH).

## 004_UltrasonicJarakLedButton.ino
The code is an Arduino sketch written in the C++ programming language. It uses an ultrasonic sensor to measure distance and display it on a 16x2 LCD screen. Additionally, it reads an analog value from pin A5, converts it to voltage, and displays it on the LCD screen. Depending on the voltage value, it also controls an LED.
The code includes the LiquidCrystal library and initializes an instance of the LiquidCrystal class named lcd with the pin connections for RS, E, D4, D5, D6, and D7 of the LCD.
In the setup() function, the code sets trigpin as an output and echopin as an input. It initializes the LCD screen with 16 columns and 2 rows using lcd.begin(16, 2). Serial communication is started with a baud rate of 9600 using Serial.begin(9600). The led pin is set as an output.
In the loop() function, the code performs the following steps repeatedly:
- It reads an analog value from pin A5 using analogRead(A5) and stores it in the variable bacaAnalog. The value is then printed to the serial monitor using Serial.println(bacaAnalog).
- It calculates the voltage value by multiplying bacaAnalog with (5.0/1023.0) and stores it in the variable tegangan.
- The LCD screen is cleared using lcd.clear(), and the cursor is set to the second row using lcd.setCursor(0, 1). The voltage value is then printed on the LCD screen using lcd.print(tegangan).
- If the tegangan value is greater than 4.0, the LED is turned on using digitalWrite(led, HIGH). Otherwise, the LED is turned off using digitalWrite(led, LOW).
- The code generates ultrasonic pulses by first setting the trigpin low, waiting for 2 microseconds, setting it high for 10 microseconds, and then setting it low again.
- The duration of the echo pulse is measured using pulseIn(echopin, HIGH) and stored in the variable duration.
- The distance in centimeters is calculated by dividing duration by 58 and stored in the variable distance.
- The LCD cursor is set to the first row using lcd.setCursor(0, 0). The distance value is then printed on the LCD screen with appropriate text using lcd.print("Jarak = "), lcd.print(distance), and lcd.print("cm").
- The code adds a delay of 300 milliseconds before repeating the loop.

## 005_SuhuDHT11.ino
The code is an Arduino sketch written in the C++ programming language. It reads an analog voltage from pin A0, converts it to a temperature in degrees Celsius, and then prints the temperature value through the serial port at a baud rate of 9600.
In the setup() function, Serial.begin(9600) initializes the serial communication with a baud rate of 9600. This allows you to communicate with the Arduino board via the serial port.
In the loop() function, the code performs the following steps repeatedly:
- int bacaAnalog = analogRead(A0); reads the analog value from pin A0 and stores it in the variable bacaAnalog. The analogRead() function converts the analog voltage to a digital value between 0 and 1023.
- float tegangan = bacaAnalog * (5.0 / 1023.0); calculates the voltage value by dividing the bacaAnalog value by 1023 (the maximum value of the ADC) and multiplying it by 5.0 (the reference voltage).
- float celcius = (tegangan - 0.5) * 100; converts the voltage value to temperature in degrees Celsius. It assumes a linear relationship between the voltage and temperature with a sensitivity of 100 degrees Celsius per volt and an offset of -0.5 volts.
- Serial.println(celcius); sends the calculated temperature value (celcius) through the serial port. The println() function prints the value followed by a line break, allowing it to be viewed in the serial monitor or received by another device connected to the serial port.

## 006_SuhuDHT11LCD.ino
The code is an Arduino sketch written in the C++ programming language. It includes libraries for the LiquidCrystal display and the DHT11 temperature and humidity sensor. The sketch reads temperature and humidity values from the DHT11 sensor and displays them on a 16x2 LCD screen. It also sends the temperature and humidity values through the serial port at a baud rate of 9600.
The code includes the necessary libraries and defines constants for the DHT11 sensor pin (DHTPIN) and the DHT sensor type (DHTTYPE). It creates instances of the DHT class and the LiquidCrystal class, specifying the LCD pin connections.
In the setup() function, the LCD screen is initialized with the size of 16 columns and 2 rows using the lcd.begin(16, 2) function. The serial communication is also initialized with a baud rate of 9600 using Serial.begin(9600). Finally, the DHT sensor is started with dht.begin().
In the loop() function, the code performs the following steps repeatedly:
- It reads the temperature and humidity values from the DHT11 sensor using dht.readTemperature() and dht.readHumidity(), respectively, and stores them in the variables suhu (temperature) and kelembaban (humidity).
- It prints the temperature and humidity values to the serial monitor using Serial.print() and Serial.println().
- It clears the LCD screen using lcd.clear() and sets the cursor to the beginning of the first row using lcd.setCursor(0, 0).
- It displays the temperature value on the LCD screen using lcd.print("Suhu C: ") and lcd.print(suhu).
- It sets the cursor to the beginning of the second row using lcd.setCursor(0, 1).
- It displays the humidity value on the LCD screen using lcd.print("Kelembaban: ") and lcd.print(kelembaban).
- It adds a delay of 2000 milliseconds (2 seconds) using delay(2000) to control the update rate of the temperature and humidity values.
