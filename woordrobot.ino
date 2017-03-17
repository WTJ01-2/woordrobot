byte pins [] = {5,4,6,7,3 };
byte motorpin [] = {pins[0],pins[2]};
byte richtingpin [] = {pins[1],pins[3]};
void setup() {
  Serial.begin(9600);
  for(byte i = 0; i < sizeof(pins);i++) {
    pinMode(i, OUTPUT);
  }
}

void loop(){
  draai(255,false,3);
  delay(3000);
  draai(255,true,3);
  delay(3000);
  rijd(255, true,3);
  delay(3000);
  rijd(255,false,3);
  delay(3000);
}

// Functie om motoren te laten draaien, motor moet 1 of 2 zijn, power tot 255, 
void motor(byte motor, byte power, boolean richting) {
  if (richting) {
   digitalWrite(richtingpin[motor-1], HIGH); 
  } else {
    digitalWrite(richtingpin[motor-1], LOW);
  }
    analogWrite(motorpin[motor-1], power);
}

// Rijd voor of achteruit voor een bepaalde tijd in seconden
void rijd(byte power, boolean richting, int duur) {
 motor(1,power,richting);
 motor(2,power,richting);
 delay(duur*1000);
 stastil();
}

// Stop met rijden
void stastil() {
 rijd(0, false, 0); 
}

// Draai de robot voor een bepaalde tijd
void draai(byte power, boolean richting, int duur) {
  motor(1,power,richting);
  motor(2,power,!richting);
  delay(duur*1000);
  stastil();
}

