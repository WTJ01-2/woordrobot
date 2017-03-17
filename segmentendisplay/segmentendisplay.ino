void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
 // Serial.begin(9600);
}

void loop()
{
    schrijfcijfer(1);
}

void schrijfl(){
    digitalWrite(1, LOW);
    digitalWrite(13, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
    digitalWrite(3, LOW); // GROUND
    digitalWrite(2, HIGH); // GROUND
}
void dimmen(){
    digitalWrite(1, LOW);
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);

}
void schrijfcijfer(int cijfer){
  schrijfl();
  delay(10);
  digitalWrite(3, HIGH); // GROUND
  digitalWrite(2, LOW); // GROUND
} 

