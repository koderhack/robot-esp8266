#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Hash.h>
#include "webcode.h"

/* define L298N or L293D motor control pins */
int leftMotorForward = 2;     /* GPIO2(D4) -> IN3   */
int rightMotorForward = 15;   /* GPIO15(D8) -> IN1  */
int leftMotorBackward = 0;    /* GPIO0(D3) -> IN4   */
int rightMotorBackward = 13;  /* GPIO13(D7) -> IN2  */


/* define L298N or L293D enable pins */
int rightMotorENA = 14; /* GPIO14(D5) -> Motor-A Enable */
int leftMotorENB = 12;  /* GPIO12(D6) -> Motor-B Enable */

const char ssid[] = "FunBox3-F9EA";       // your network SSID (name)
const char password[] = "23PMUFRSAL4Y";  // your network key
char Data;
 //For ESP8266 and ESP32 boards




ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  // initialize motor control pins as output
  pinMode(leftMotorForward, OUTPUT);
  pinMode(rightMotorForward, OUTPUT); 
  pinMode(leftMotorBackward, OUTPUT);  
  pinMode(rightMotorBackward, OUTPUT);

  // initialize motor enable pins as output
  pinMode(leftMotorENB, OUTPUT); 
  pinMode(rightMotorENA, OUTPUT);

  // start the web server
  server.on("/",[]() {

  server.send(200, "text/html", webcode);

  });

  server.on("/forward", []() {
    MotorStop();
    MotorForward();
    server.send(200, "text/html", webcode);
    
  });
  server.on("/backward", []() {
    MotorStop();
    MotorBackward();
   
  server.send(200, "text/html", webcode);
  });
  server.on("/left", []() {
    MotorStop();
    TurnLeft();

  server.send(200, "text/html", webcode);
  });
  server.on("/right", []() {
    MotorStop();
    TurnRight();
  
server.send(200, "text/html", webcode);
  });
  server.on("/stop", []() {
    MotorStop();

    server.send(200, "text/html", webcode);
  });
  server.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: " + WiFi.localIP().toString());
}

void loop() {
  server.handleClient();
}



/********************************************* FORWARD *****************************************************/
void MotorForward(void)   
{
  digitalWrite(leftMotorENB,HIGH);
  digitalWrite(rightMotorENA,HIGH);
  digitalWrite(leftMotorForward,HIGH);
  digitalWrite(rightMotorForward,HIGH);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorBackward,LOW);
}

/********************************************* BACKWARD *****************************************************/
void MotorBackward(void)   
{
  digitalWrite(leftMotorENB,HIGH);
  digitalWrite(rightMotorENA,HIGH);
  digitalWrite(leftMotorBackward,HIGH);
  digitalWrite(rightMotorBackward,HIGH);
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(rightMotorForward,LOW);
}

/********************************************* TURN LEFT *****************************************************/
void TurnLeft(void)   
{
  digitalWrite(leftMotorENB,HIGH);
  digitalWrite(rightMotorENA,HIGH); 
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(rightMotorBackward,HIGH);

}

/********************************************* TURN RIGHT *****************************************************/
void TurnRight(void)   
{
  digitalWrite(leftMotorENB,HIGH);
  digitalWrite(rightMotorENA,HIGH);
  digitalWrite(leftMotorBackward,HIGH);
  digitalWrite(rightMotorForward,LOW);

}

/********************************************* STOP *****************************************************/
void MotorStop(void)   
{
  digitalWrite(leftMotorENB,LOW);
  digitalWrite(rightMotorENA,LOW);
  digitalWrite(leftMotorForward,LOW);
  digitalWrite(leftMotorBackward,LOW);
  digitalWrite(rightMotorForward,LOW);
  digitalWrite(rightMotorBackward,LOW);
}
