//#include <ESP8266WiFi.h>

bool sw = true;

void setup() {
  Serial.begin(9600);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
}

void loop() {
  
  if(sw){
    digitalWrite(21, LOW);
    sw = false;
   // Serial.println(" * * * * * LEFT");
  }
  else{
    digitalWrite(21, HIGH);
    sw = true;
   // Serial.println(" * * * * * RIGHT");
  }
  for(int i = 0; i < 830; i++){

    digitalWrite(22, HIGH);
    delayMicroseconds(800);
    //Serial.println("HIGH");
    digitalWrite(22, LOW);
    delayMicroseconds(800);
    //Serial.println("LOW");
  }

}
