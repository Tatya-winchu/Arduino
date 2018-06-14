/* Distance Measurement Ultrasonic Sensor 
Sensor is interfaced to Arduino Uno R3 and output is displayed on 16*2 LCD*/

#include<LiquidCrystal.h>//include LCD library
LiquidCrystal myLCD(10,9,5,4,3,2);//naming the LCD object telling arduino how we hooked LCD
int trigPin=13;//trig Pin of Sensor to 13
int echoPin=11;//Eccho pin of sensorcto 11
int LEDPin=6;//LED indicator Pin
long duration;//to calculate pulse duration
double distance;//to calculate distance
void setup() {
 pinMode(trigPin,OUTPUT);//trig output port
 pinMode(echoPin,INPUT);//EchoPin INPUT 
 pinMode(LEDPin,OUTPUT);//Indication of traget 
 myLCD.begin(16,2);//LCD 16*2(column by Row)
 myLCD.setCursor(0,0);//set LCD cursor to Row0Cloumn0 i.e at start
 myLCD.print("Target Distance:  ");//what to print in LCD 
 
}

void loop() {
    //starting the pulse LOW HIGH LOW HIGH
    Serial.begin(9600);
  digitalWrite(trigPin,LOW);//creating Low trig
  delayMicroseconds(2000);
  //now will set the trigger pin high
  digitalWrite(trigPin,HIGH);//creating High
  delayMicroseconds(2000);
  digitalWrite(trigPin,LOW);//creating LOW trig
 //now will read the input from echo pin and measure
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2.;
if(distance<10.0){
      digitalWrite(LEDPin,HIGH);//target is too close
      Serial.println("On");
    }
    if(distance>10.0){
      digitalWrite(LEDPin,LOW);//target id not in close zone
    }
    myLCD.setCursor(0,1);  //Set cursor to first column of second row
    myLCD.print("             "); //Print blanks to clear the row
    myLCD.setCursor(0,1);//set cursor to first column and 0 row
    myLCD.print(distance);//printing distance
    myLCD.print(" Cm");//Unit of distance 
    delay(250);//delay to avoid jittery display
    
  }


