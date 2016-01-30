# Embedded Systems Laboratory Works

####Practical assignments for embedded systems courses.
All laboratory works are written in `C` using Atmel Studio and for simulation is used Proteus. Each folder contains the code and Proteus project. The MCU that is used in this laboratory works is ATMega32.

## Tasks:
### Lab 1
Write a program for a microcontroller that will be able to read messages from the standard I/O and write messages back. Input messages will be decoded and will switch on or off a LED. Connect the I/O library to the serial interface so the messages will be received though it and display.

### Lab 2
Write a program for a microcontroller that will be able to read characters from keypad and display those characters on LCD.

### Lab 3
Write an application that will read an analog value from ADC and convert this value to the temperature. The result will be displayed to the standard output interface LCD or to virtual terminal.

### Lab 4
Define, develop an app based on MCU that will collect the temperature level from the sensor adc to display to the standard output. The value of the temperature will be displayed in degree Celcius and could be switched to the Kelvin or Fahrenheit by having an input from the standard Input Interface. In order to avoid the frozen of data collection it is recommended data collection to be implemented using a timer + auto trigger mode of ADC.

### Lab 5
To develop an application based on MCU that will read an analog input and will set the rotation speed of a motor. The motor could be rotated in two directions and the speed would be as positive as negative. The maximum value of the input signal will influence the motor to rotate maximum in clockwise direction. The maximum value of input signal will set rotation counterclockwise rotation.The half value (middle point of input signal) will make motor to stop.

### Lab 6
To develop a system for controlling voltage using the PID control system.

### Lab 7
Using FreeRtos OS create the following tasks:
1. Task, that toggles a led.
2. Task, which reads a button, and will sat a semaphore.
3. Will wait for semaphore, and will toggle led, and take semaphore.