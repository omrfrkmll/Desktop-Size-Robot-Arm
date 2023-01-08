#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10
#define x_axis A0 // x axis
#define y_axis A1 //y axis
#define button1 8 // joystick button
#define button2 2 // A button
#define button3 3 // B button
#define button4 4 // C button
#define button5 5 // D button
#define button6 6 // E button
#define button7 7 // F button

RF24 radio(9, 10); // CE, CSN


const byte address[6] = "00001";
int data[9];  

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  Serial.begin(9600);
}

void loop() {
  //const char text[] = "Hello World";
  //radio.write(&text, sizeof(text));
  //delay(1000);
  data[0] = analogRead(x_axis);
  data[1] = analogRead(y_axis);
  data[2] = digitalRead(button1);
  data[3] = digitalRead(button2);
  data[4] = digitalRead(button3);
  data[5] = digitalRead(button4);
  data[6] = digitalRead(button5);
  data[7] = digitalRead(button6);
  data[8] = digitalRead(button7);
  radio.write( data, sizeof(data) ); 
 
//HATA AYIKLAMA (DEBUG)
  Serial.print("x: ");
  Serial.print(analogRead(x_axis));
  Serial.print(" ");
  Serial.print("y: ");
  Serial.print(analogRead(y_axis));
  Serial.print(" ");
  Serial.print("JB: ");
  Serial.print(digitalRead(button1));
  Serial.print(" ");
  Serial.print("A: ");
  Serial.print(digitalRead(button2));
  Serial.print(" ");
  Serial.print("B: ");
  Serial.print(digitalRead(button3));
  Serial.print(" ");
  Serial.print("C: ");
  Serial.print(digitalRead(button4));
  Serial.print(" ");
  Serial.print("D: ");
  Serial.print(digitalRead(button5));
  Serial.print(" ");
  Serial.print("E: ");
  Serial.print(digitalRead(button6));
  Serial.print(" ");
  Serial.print("F: ");
  Serial.print(digitalRead(button7));
  Serial.println(" ");
  //Serial.print(digitalRead(BUTON));
  delay(300);
}