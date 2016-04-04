/*
 This code allows the user to control 1 of the arduinos output pins from the console, turning it on and off
 and delaying them.
 
 author: soren bouma 4/4/2016
 
 to control the arduino, just type a sequence of characters into the console
 >a turns LED off
 >b turns LED on
 >typing a number n will cause a delay of n seconds before the next command character is read

 for example a1b1a1b1a1b1a1b1 will cause the light to flash on and off




 POTENTIAL ISSUES:
 >doesn't accept delays any more precise than 1 second - but this is easy to fix
 >once a sequence has been typed in, user can't stop it until it is finished - probably harder to fix
 >can't accept time delays longer than 9 seconds without user having to type the same number in multiple times
 (eg to get a delay of 90 seconds, you have to type a9999999999b) but this can be easily 
 fixed with a function in the python interface
 */
int ledPin=8;
// int delayTime=0;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}
void loop(){
  if (Serial.available()) {
    int ser=Serial.read();     //read the serial input
    Serial.println("value read from serial:");
    Serial.println(ser);
    delay(10);
    if (ser == 97) {
      //if user presses key 'a', turn LED on
      Serial.println("turning LED 1 on");
      digitalWrite(ledPin,HIGH);
      //delay(3000);
    }
    if (ser == 98) {
      //if user presses key 'b' turn the LED off
      Serial.println("turning LED 1 off");
      digitalWrite(ledPin,LOW);
    }
    if (ser >= 49 and ser < 57) {
      // if user types a number 0-9, delay for that many seconds before executing next command
      Serial.println("delaying by this many seconds: ");
      Serial.println(ser-48);
      delay((ser-48)*1000);
    }
  }
}
