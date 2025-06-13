const int trigpin = 2;
const int echopin = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  long duration, inches, cm;

  duration = pulseIn(echopin, HIGH);
  inches = microsecondsToInches(duration);
  Serial.print(inches);
  Serial.print("In ");

  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm ");

  Serial.println();

  delay(1000);
  
}

long microsecondsToInches(long microseconds){
  return microseconds/74/2;

}

long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;

} 




