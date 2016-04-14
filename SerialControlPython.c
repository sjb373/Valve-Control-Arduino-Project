/*
 This code allows the user to control 1 of the arduinos output pins from the console, turning it on and off
 and delaying them. This one is intended for use with the python interface.
 
 author: soren bouma 4/4/2016
 
 to control the arduino, just use the send() function in the python interface on a list of string commands
 >a turns LED a on, b turns led b on
 >x turns led a off,y turns b off
 s shuts down every led
 o turns on every led
 >typing a number n will cause a delay of n seconds before the next command character is read
 for example a1x1a1x1a1x1a1x1 will cause the led a to flash on and off
 POTENTIAL ISSUES:
 >doesn't accept delays any more precise than 1 second - but this is easy to fix
 >once a sequence has been typed in, user can't stop it until it is finished - probably harder to fix
 >can't accept time delays longer than 9 seconds without user having to type the same number in multiple times
 (eg to get a delay of 90 seconds, you have to type a9999999999b) but this can be easily 
 fixed with a function in the python interface
 */
int aPin=8;
int bPin=9;
int cPin=10;
// int delayTime=0;

void setup(){
  Serial.begin(9600);
  // print instructions to serial
  Serial.println("READY");
  pinMode(aPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(cPin,OUTPUT);

}
void loop(){
  if (Serial.available()) {
    int ser=Serial.read();     //read the serial input
    //Serial.println("value read from serial:");
    //Serial.println(ser);
    delay(5);
    if (ser == 97) {
      //if user presses key 'a', turn LED a on
      //Serial.println("turning LED a (red) on");
      digitalWrite(aPin,HIGH);
      //delay(3000);
    }
    if (ser == 98) {
      //if user presses key 'b' turn LED b on
      //Serial.println("turning LED b(yellow) on");
      digitalWrite(bPin,HIGH);
    }
     if (ser == 99) {
      //if user presses key 'c' turn LED c on
      //Serial.println("turning LED c(green) on");
      digitalWrite(cPin,HIGH);
    }
     if (ser == 120) {
      //if user presses key 'x' turn LED a off
      //Serial.println("turning LED a(Red) off");
      digitalWrite(aPin,LOW);
    }
     if (ser == 121) {
      //if user presses key 'y' turn LED b off
      //Serial.println("turning LED b(yellow) off");
      digitalWrite(bPin,LOW);
    }
    if (ser == 122) {
      //if user presses key 'z' turn LED c off
      //Serial.println("turning LED c(green) off");
      digitalWrite(cPin,LOW);
    }
    //THE NEXT IF STATEMENT IS COMMENTED OUT, BECAUSE IN THE PYTHON INTERFACE, DELAYS ARE DONE IN PYTHON, NOT ON BOARD
    //if (ser >= 49 and ser < 57) {
      // if user types a number 0-9, delay for that many seconds before executing next command
      //Serial.println("delaying by this many seconds: ");
      //Serial.println(ser-48);
      //delay((ser-48)*1000);
    //}
     if (ser == 115) {
      // if user types s, turn everything off
      //Serial.println("turning everything off");
      //Serial.println(ser-48);
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);

    }
     if (ser == 111) {
      // if user types o, turn everything on
      //Serial.println("turning everything on");
      //Serial.println(ser-48);
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,HIGH);

    }
  }
}
