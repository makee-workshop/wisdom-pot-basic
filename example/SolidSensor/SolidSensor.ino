int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);

  Serial.print(sensorValue);
  Serial.println("/1024");

  delay(1000);
   
}
