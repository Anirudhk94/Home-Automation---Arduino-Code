#include <SoftwareSerial.h>
#define relay1 2
#define relay2 3
#define relay3 4
#define relay4 5

//SoftwareSerial BT(5,6); 
SoftwareSerial mySerial(9, 10);

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);

  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to recieve a live SMS
  delay(1000);

  mySerial.println("AT+CMGD=1"); //Delete Message at index 1
  mySerial.println("AT+CMGD=2"); 
  mySerial.println("AT+CMGD=3");
  mySerial.println("AT+CMGD=4");
  mySerial.println("AT+CMGD=5");
  
  mySerial.println("AT+CMGL=\"ALL\""); 
  delay(10);
  
//  BT.begin(9600); // set the data rate for the SoftwareSerial port
//  delay(100);
  
  pinMode(13, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  
  

}

char a;  // stores incoming character from other device
void loop()
{
 if (mySerial.available()>0) {
     char c = mySerial.read();
     Serial.write(c);
     
     //RELAY at PIN 2
     if(c=='1') {
      digitalWrite(13, HIGH); 
      digitalWrite(relay1, HIGH);    //relay open 
      //mySerial.println("AT+CMGD=1");
     }
     if(c=='2') {
      digitalWrite(relay1, LOW);    //relay close
      digitalWrite(13, LOW);
      //mySerial.println("AT+CMGD=1");
     } 

     //RELAY at PIN 3
      if (a=='3') {
        digitalWrite(relay2, HIGH);    //relay open
        //digitalWrite(13, HIGH);
        Serial.println("LED on");
      }
      if (a=='4') {
        digitalWrite(relay2, LOW);    //relay close
        //digitalWrite(13, LOW);
        Serial.println("LED off");
      }

      
      //RELAY at PIN 4
      if (a=='5') {
        digitalWrite(relay3, HIGH);    //relay open
        //digitalWrite(13, HIGH);
        Serial.println("LED on");
      }
      if (a=='6') {
        digitalWrite(relay3, LOW);    //relay close
        //digitalWrite(13, LOW);
        Serial.println("LED off");
      }

      
      //RELAY at PIN 5
      if (a=='7') {
        digitalWrite(relay4, HIGH);    //relay open
        //digitalWrite(13, HIGH);
        Serial.println("LED on");
      }
      if (a=='8') {
        digitalWrite(relay4, LOW);    //relay close
        //digitalWrite(13, LOW);
        Serial.println("LED off");
      }
 }

 if (Serial.available()) { // if text arrived in from BT serial...
      a=(Serial.read());
      Serial.write(a);
      
      //RELAY at PIN 2
      if (a=='1') {
        digitalWrite(relay1, HIGH);    //relay open
        //digitalWrite(13, HIGH);
        Serial.println("LED on");
      }
      if (a=='2') {
        digitalWrite(relay1, LOW);    //relay close
        //digitalWrite(13, LOW);
        Serial.println("LED off");
      }

      
      //RELAY at PIN 3
      if (a=='3') {
        digitalWrite(relay2, HIGH);    //relay open
        //digitalWrite(13, HIGH);
        Serial.println("LED on");
      }
      if (a=='4') {
        digitalWrite(relay2, LOW);    //relay close
        //digitalWrite(13, LOW);
        Serial.println("LED off");
      }

      
      //RELAY at PIN 4
      if (a=='5') {
        digitalWrite(relay3, HIGH);    //relay open
        //digitalWrite(13, HIGH);
        Serial.println("LED on");
      }
      if (a=='6') {
        digitalWrite(relay3, LOW);    //relay close
        //digitalWrite(13, LOW);
        Serial.println("LED off");
      }

      
      //RELAY at PIN 5
      if (a=='7') {
        digitalWrite(relay4, HIGH);    //relay open
        //digitalWrite(13, HIGH);
        Serial.println("LED on");
      }
      if (a=='8') {
        digitalWrite(relay4, LOW);    //relay close
        //digitalWrite(13, LOW);
        Serial.println("LED off");
      }
       
  }
}


