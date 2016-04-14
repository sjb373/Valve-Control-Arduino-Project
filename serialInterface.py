"""
This is a super basic  non graphical UI for the arduino serial written in python.
It runs in a python terminal(or command line on windows) and is intended for 
sending sequences of on/off commans to 3 digital pins on an arduino
1 dependency: pyserial https://github.com/pyserial/pyserial

To use it, type execfile('path/to/this/file')

..then use the send() function on a list of command/delay strings: they will be sent to
the arduino in order, while printing the current state of the system.
 COMMANDS:
a/b= valve 1 on/off, b/x =valve 2 on/off, c/z sparks on/off, o/s everythng on/off
integer string 'n' delays by n seconds before sending next command

For example, send(['o','2000','s','5',a']) turns everything on, waits 2 seconds,
then turns everything off, then waits 5milliseconds, then turns led a on.

As far as I can tell, all of this works properly. I am not sure how to test the
latency/
"""


#from colorama import init
#from colorama import Back, Style
import math
import serial
import time
init(autoreset=True)
def Transform(n):
  """transforms a number into a form readable byte-by-byte by the arduino"""
  if n <= 9:
    return str(n)
  remainder = n % 9
  message=""
  rng=int(math.floor(n/9))
  for i in range(rng):
    message+="9"
  message+=str(remainder)  
  message=str(message)
  return message
def has_common_chars(s1, s2):
	"""helper function, checks if 2 strings have common characters"""
	#returns True if s1, s2 have common chars
	return len(set(s1) & set(s2)) > 0
ser=serial.Serial('/dev/ttyACM0',9600)

#state={'a':0,'b':0,'c':0}
def display_state(state):
	"""prints which things are on and which things are off """
	print('Valve 1: {}'.format(state['a']) + ' | Valve 2: {}'.format(state['b'])+ ' | Spark generator: {}'.format(state['c']))
def send(cmdList):
	"""This function takes a list of commands (a/x valve 1, b/y valve 2 c/z
	spark generator, int delay) and sends them to the arduino in order"""
	stat={'a':0,'b':0,'c':0}
	for c in cmdList:	
		if not has_common_chars(c,'abcxyzso'):
			
			delaytime=float(c) / 1000
			print ('delaying by this many seconds:' + str(delaytime))
			c=Transform(int(c))
			#print('delaytime: '+str(delaytime) )
			time.sleep(delaytime)
			delaytime=0.0
			continue
		if c =='a':
			stat['a']=1
			print('turning Valve 1 on')
			display_state(stat)
		elif c == 'b':
			stat['b']=1
			print('turning Valve 2 on')
			display_state(stat)
		elif c == 'c':
			stat['c']=1
			print('turning Spark Generator on')
			display_state(stat)
		elif c == 'x':
			stat['a']=0
			print('turning Valve 1 off')
			display_state(stat)
		elif c == 'y':
			stat['b']=0
			print('turning Valve 2 off')
			display_state(stat)
		elif c == 'z':
			stat['c']=0
			print('turning Spark Generator off')
			display_state(stat)
		elif c == 's':
			stat['a']=0
			stat['b']=0
			stat['c']=0
			print('turning everything off')
			display_state(stat)
		elif c == 'o':
			stat['a']=1
			stat['b']=1
			stat['c']=1
			print('turning everything on')
			display_state(stat)
		ser.write(c)
print('Welcome to the python UI')
print('to send commands to arduino, just use the send function on a list of command strings')
print(''o' and 's' turns everything on and off, abc and xyz turn v1 v2 sg on or off')
print('a number string n will delay by n milliseconds before executing next command')
print('example: send')


