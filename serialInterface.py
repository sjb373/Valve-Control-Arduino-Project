
import serial as s
def Transform(n):
  #transforms a number into a form readable by the arduino code
  if n <= 9:
    return n
  remainder = n % 9
  message=[]
  rng=int(n/9)
  for i in range(rng):
    message.append(9)
  message=str(message)
  return message
def CmdListToSerial(cmdList,ser):
  for char in cmdList:
    if char in 'qwertuipsdfghjklmnbv:,.':
      print('recieved unrecognised command')
      
    elif char in 'abcsoxyz':
      ser.write(a)
    else:
      ser.write(Transform(a))

#changed = False
#while True:
#  if changed=True:
#    print('CURRENT STATE:')
#    print('valve 1: ' + v1STate '| valve 2:' + v2state ' | spark generator: ' + SGstate)
#    changed = False
#  cmdSeq = input('next command sequence?')
#  for char in list(cmdSeq):
#    
