byte pins [] = {5,4,6,7, 1, 2, 3, 8, 9, 10, 11, 12, 13 };
byte motorpin [] = {pins[0],pins[2]};
byte richtingpin [] = {pins[1],pins[3]};

boolean rechts = false;
boolean links = true;

boolean achteruit = false;
boolean vooruit = true;

char woord[] = {'M', 'A', 'X'};

boolean start = false;

void setup() {
  Serial.begin(9600);
  for(byte i = 0; i < sizeof(pins);i++) {
    pinMode(i, OUTPUT);
  }
  
  // pins voor lijnsensoren
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
  // pin voor startknop
  pinMode(A3, INPUT);
}

void loop(){
  while(!start) {
     start = checkbutton(); 
  }
  schrijfletter('A');
  
  // Einde van de loop
  start = false;
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
      schrijfm();
      break;
    case 'U':
      schrijfu();
      break;
    case 'X':
      break;
  }
}
void tiencmomhoog(){
  rijd(1.5);
}

void schrijfa(){
  //eerst draai
  draai(1, rechts); // 1
  rijd(2);
  //2e streep A
  draai(2, links); // -1
  rijd(2, achteruit);
  //Terug over zelfde lijn voor middelste streep A
  rijd(0.8);
  //Draai voor middelste streep A
  draai(2.5, links); //-2.5
  //Middelste streep
  rijd(1);
  draai(2.5, links); //-5
  rijd(2);
  draai(1, links); //-6
  
  
  /*rijd(255,false,1);
  draai(200,false,2);
  rijd(255,false,2);*/
}

void schrijfm(){
/*  rijd(255,true,2.2);
  draai(200,true, 1);
  rijd(255,false,1);
  draai(200,false,1.8);
  rijd(255,true,1);
  draai(200,true,1.5);
  rijd(255,false,2.2);*/
}
void schrijfu(){/*
  rijd(255,true,2.2);
  rijd(255,false,2.2); 
  draai(255,true, 4);
  rijd(255,false,1);
 */ 
}

// Rijd voor of achteruit voor een bepaalde tijd in seconden
void rijd(float duur, boolean richting, byte power) {
    motor(1, power, richting);
    if(richting) {
        motor(2,power-40,richting);
    } else{
        motor(2,power-40,richting);  
    }
    //motor(2,power,richting);
    delay(duur*1000);
    stastil();
}

void rijd(float duur, boolean richting) {
    byte power = 255;
    rijd(duur, richting, power);
}

void rijd(float duur) {
  byte power = 255;
  boolean richting = vooruit;
  rijd(duur, richting, power);
}

// Stop met rijden
void stastil() {
 motor(1, 0, false); 
 motor(2, 0, false);
}

// Draai de robot voor een bepaalde tijd
// 1 seconde = 60 graden draai
// 3 seconden = 180 graden
void draai(int duur, boolean richting, byte power) {
  if(power > 215) power = 215
  motor(1,power,richting);
  motor(2,power+40,!richting);
  delay(duur*1000);
  stastil();
}

void draai(int duur, boolean richting) {
  byte power = 200;
  draai(duur, richting, power);
}

void toonnummer(int nummer) {
  toonL();
  delay(5);
  
  digitalWrite(3, HIGH); // GROUND
  digitalWrite(2, LOW); // GROUND
  switch (nummer){
    case 0:
      digitalWrite(1, LOW);
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(12, HIGH); 
      break;
    case 1:
      digitalWrite(1, LOW);
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(12, HIGH); 
      break;
    case 2:
      digitalWrite(1, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(12, LOW); 
      break;
    case 3:
      digitalWrite(1, HIGH);
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(12, HIGH); 
      break;
    case 4:
      digitalWrite(1, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(12, HIGH); 
      break;
    case 5:
      digitalWrite(1, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(12, HIGH); 
      break;
    case 6:
      digitalWrite(1, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(12, HIGH); 
      break;
    case 7:
      digitalWrite(1, LOW);
      digitalWrite(13, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(12, HIGH); 
      break;
    case 8:
      digitalWrite(1, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(12, HIGH); 
      break;
    case 9:
      digitalWrite(1, HIGH);
      digitalWrite(13, HIGH);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(12, HIGH); 
      break;
  }
  
  
  delay(5);
}

void toonL() {
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

void toonniks() {
  digitalWrite(1, LOW);
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(12, LOW);
}

boolean checkbutton(){
 int buttonstate = analogRead(A3);
 if(buttonstate > 1020) {
  return true;
 } else {
  return false; 
 }
}

