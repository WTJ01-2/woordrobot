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
  //draai(255,false,3);
  //delay(3000);
  //draai(255,true,3);
  //delay(3000);
  //rijd(255, true,1);
  //delay(500);
  //rijd(255,false,1);
  //delay(3000);
  schrijfletter('A');
  delay(100000);
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

void schrijfletter(char L){
  //tiencmomhoog();
  switch (L){
    case 'A':
      schrijfa();
      break;
    case 'M':
      break;
    case 'X':
      break;
  }
}
void tiencmomhoog(){
  rijd(255,true, 1.2);
}
void schrijfa(){
  //rijd(255,true, 2);
  draai(200,true, 1);
  rijd(255,true,2);
  draai(200,false,1.5);
  rijd(255,false,2);
  rijd(255,true,1);
  draai(200,false,1);
  rijd(255,true,0.5);
  draai(200,true,1);
  rijd(255,false,1);
  
}
// Rijd voor of achteruit voor een bepaalde tijd in seconden
void rijd(byte power, boolean richting, float duur) {
 motor(1,power,richting);
 if(richting){
 motor(2,power-20,richting);
 } else{
 motor(2,power-40,richting);  
 }
 delay(duur*1000);
 stastil();
}

// Stop met rijden
void stastil() {
 motor(1, 0, false); 
 motor(2, 0, false);
}

// Draai de robot voor een bepaalde tijd
void draai(byte power, boolean richting, int duur) {
  motor(1,power,richting);
  motor(2,power,!richting);
  delay(duur*1000);
  stastil();
}

// Rijd voor of achteruit voor een bepaalde tijd in seconden
void rijd(byte powerlinks, byte powerrechts, boolean richting, float duur) {
 motor(1,powerlinks,richting);
 if(richting){
 motor(2,powerrechts,richting);
 } else{
 motor(2,powerrechts,richting);  
 }
 delay(duur*1000);
 stastil();
}

