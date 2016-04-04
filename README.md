# Valve-Control-Arduino-Project

 This code allows the user to control 1 of the arduinos output pins from the console, turning it on and off
 and delaying them.
 
 author: soren bouma 4/4/2016
 
 to control the arduino, just type a sequence of characters into the console
 
 a turns LED off
 
 b turns LED on
 
 typing a number n will cause a delay of n seconds before the next command character is read
 
 for example a1b1a1b1a1b1a1b1 will cause the light to flash on and off
 
 
 POTENTIAL ISSUES:
 
 Doesn't accept delays any more precise than 1 second - but this is easy to fix
 
 Once a sequence has been typed in, user can't stop it until it is finished - probably harder to fix
 
 Can't accept time delays longer than 9 seconds without user having to type the same number in multiple times
 (eg to get a delay of 90 seconds, you have to type a9999999999b) but this can be easily 
 fixed with a function in the python ui i will eventually make
