#include <Servo.h>

Servo myservo;

const int soilMoisturePin = A0;
int val;

void setup() {
  myservo.attach(6);
  val = 0;
  myservo.write(val);

  Serial.begin(9600);

  pinMode(soilMoisturePin, INPUT);

}

void loop() {

// FOR TESTING WITHOUT BLUETOOTH
  int moistValue = analogRead(soilMoisturePin);

    Serial.print("Moisture Value: ");
    Serial.print(moistValue);

    if (moistValue <= 500){
      val = 180;
      Serial.println(" IT'S RAINING!");
    } else {
      val = 0;
      Serial.println(" It's dry.");
    }
    
    myservo.write(val);
    Serial.println(val);


    delay(1000);
}
