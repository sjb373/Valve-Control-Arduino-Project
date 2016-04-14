# Valve-Control-Arduino-Project

 This code allows the user to control 1 of the arduinos output pins from the console, turning it on and off
 and delaying them. 
 
 author: soren bouma
 
 to control the arduino from arduino serial monitor
 
 1)Upload workingLEDserialControl.c to the arduino
 
 2) open the serial monitor and just type a sequence of characters, then press enter
 
a/b= valve 1 on/off, b/x =valve 2 on/off, c/z sparks on/off, o/s everythng on/off
number n delays by n seconds before sending next command


  for example a1b1a1b1a1b1a1b1 will cause  light 1 to flash on and off
 
 IMPORTANT: you can only delay up to 9 ms at a time when controlling arduino through console. If you want an easy way to type longer delays, run the python interface and use the send() function
 

 
 
 To control the arduino using the python UI:
 
 
 1) Make sure you have python and pyserial installed and working
 
 2) Upload SerialControlPython.c
 
 3) make sure line 45 has a string with the path to the port your arduino is on
 
 2) open python shell and type >>execfile('serialInterface.py')
 
 3) make a list of command strings, eg l=['o','200','x'] - turns everything on, waits 0.2 seconds, turns led 1 off
 
 4) use the send function on the list, eg send(l)
 
 POTENTIAL ISSUES:
 
Everything works on my setup. I'm not sure what the latency/precision is, my reaction times aren't fast enough to test it.
Make sure line 45 of the python interface uses the same serial path as your arduino
