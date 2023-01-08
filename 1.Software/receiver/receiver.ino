#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(8, 7); // CE, CSN

const byte address[6] = "00001";

//motorların kontrolü için tanımladığımız kod
int data[9]; 
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
int pos1=90,pos2=90,pos3=90,pos4=90,pos5=90,pos6=90,pos7=90;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  

}

void loop() {
  //ground servo kodu -->>
  if(data[0]>=600){
    pos1++;
    servo1.write(pos1);
    delay(30);
  }
  if(data[0]<=400){
    pos1--;
    servo1.write(pos1);
    delay(30);
  }
  //<-- ground servo kodu
if(data[1]>=600){
    pos2++;
    servo2.write(pos2);
    delay(30);
  }
  if(data[1]<=400){
    pos2--;
    servo2.write(pos2);
    delay(30);
  }
  if(data[3]==0){
    pos3++;
    servo3.write(pos3);
    delay(30);
  }
  if(data[5]==0){
    pos3--;
    servo3.write(pos3);
    delay(30);
  }
  if(data[4]==0){
    pos4++;
    servo4.write(pos4);
    delay(30);
  }
  if(data[6]==0){
    pos4--;
    servo4.write(pos4);
    delay(30);
  }
  if(data[7]==0){
    pos5++;
    servo5.write(pos5);
    delay(30);
  }
  if(data[8]==0){
    pos5--;
    servo5.write(pos5);
    delay(30);
  }

  if ( radio.available() ) //Eğer sinyal algılarsan...
  {
    radio.read( data, sizeof(data) );
    Serial.print("x=");
    Serial.print(data[0]);
    Serial.print(" y=");
    Serial.print(data[1]);
    Serial.print(" JB=");
    Serial.print(data[2]);
    Serial.print(" A=");
    Serial.print(data[3]);
    Serial.print(" B=");
    Serial.print(data[4]);
    Serial.print(" C=");
    Serial.print(data[5]);
    Serial.print(" D=");
    Serial.print(data[6]);
    Serial.print(" E=");
    Serial.print(data[7]);
    Serial.print(" F=");
    Serial.println(data[8]);
    

  }
}