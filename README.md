# A-digital-watch-program
This is a lab work of Microprocessors - Micro Controllers Subject

IDE used for this lab: MPLAB X IDE

Running on the microprocessor PIC18F8722

Embedded board used for this lab: PICDEM PIC18 Explorer Demonstration Board

A program that mimics a Casio digital watch. A program has

-          A normal clock that shows hours, minutes, and seconds on the LCD screen.

-          A stopwatch that shows minutes, seconds and 1/100 second

-          We use RA5 to change modes of a digital watch. Every time RA5 is pressed, the watch will change to the next mode.

o   Mode 0: runs normal clock (default)

o   Mode 1: modifies hours. In this mode, the hour number is blinky, and RB0 is used for increasing the hour number.  If the button RB0 is keep pressed more than 1 second, the hour number will increase automatically, i.e., 5 times per second. Please note that the hour number should be returned to 0 when it reaches 23.

o   Mode 2: modifies minutes. Similar to mode 1, the minute number is blinky and increases when RB0 is pressed.

o   Mode 3: modifies seconds. Similar to mode 1, the second number is blinky and increases when RB0 is pressed.

o   Mode 4: runs a stopwatch. Using RB0 to start and stop the watch.  

-          While the stopwatch is running, the normal clock is still running in the background.


 
