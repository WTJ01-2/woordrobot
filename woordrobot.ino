byte pins [] = {5,4,6,7 };
byte motorpin [] = {pins[0],pins[2]};
byte richtingpin [] = {pins[1],pins[3]};
int motor_rechts = 1; //1 IS RECHTS
int motor_links = 2; //2 IS LINKS

char woord[] = {'M', 'A', 'X'};

int sensor1 = analogRead(A0);
int sensor2 = analogRead(A1);
int sensor3 = analogRead(A2);

boolean opzoekNaarLijn = false;
String loopstatus = "start";
int sensor1licht = 0;
int sensor2licht = 0;
int sensor3licht = 0;
int sensor1donker = 0;
int sensor2donker = 0;
int sensor3donker = 0;

boolean rechts = false;
boolean links = true;

boolean achteruit = false;
boolean vooruit = true;

boolean start = false;

void setup() {
  //Serial.begin(9600);
  for(byte i = 0; i < sizeof(pins);i++) {
    pinMode(i, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
  }
  
  // pins voor lijnsensoren
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);

  // pin voor startknop
  pinMode(A3, INPUT);
}

void loop(){
//    Serial.println("Sensor 1 min: ");
//    Serial.println(sensor1licht);
//    Serial.println("Sensor 1 max: ");
//    Serial.println(sensor1donker);
//    
//    Serial.println("Sensor 2 min: ");
//    Serial.println(sensor2licht);
//    Serial.println("Sensor 2 max: ");
//    Serial.println(sensor2donker);
//    
//    Serial.println("Sensor 3 min: ");
//    Serial.println(sensor3licht);
//    Serial.println("Sensor 3 max: ");
//    Serial.println(sensor3donker);
//  Serial.println("Sensor 2 min: " + sensor2licht+" max: "+sensor2donker);
//  Serial.println("Sensor 3 min: "+sensor3licht+" max: "+sensor3donker);
//  
//  
    
    
    while(!start) {
     start = checkbutton(); 
  }
  
      if(scanVeld()) return;
      if(opzoekNaarLijn)
      {
        zoekReferentieLijn();
        return;
      }
      rijd(0.8);
      for(int i = 0; i < sizeof(woord); i++) {
        char letter = woord[i];
        Serial.println(letter);
        Serial.println("Begin nu aan 10cm omhoog");

        tiencmomhoog(i+1);
        
        Serial.println("schrijf de letter");
        schrijfletter(letter);
        Serial.println("Terug naar referentielijn");
        zoekReferentieLijn();
        //rijd(1.5);
        Serial.println("op referentielijn, rij nog even door en draai 90 graden");
        rijd(0.8);
        draai(1.7, links);
        Serial.println("Rij over referentielijn");
        rijd(2.5);
        Serial.println("Letter A? rij extra ver");
        if(letter=='A') rijd(1.3);
        Serial.println("Positie voor volgende letter");
        if(letter!='X') draai(1.7, links);
      }
      zoekReferentieLijn();
      draai(1.7, rechts);
      zoekReferentieLijn();
      start=false;
      delay(32767);
      delay(32767);
    //}
}


boolean zoekReferentieLijn()
{
  sensor1 = analogRead(A0);
  sensor2 = analogRead(A1);
  sensor3 = analogRead(A2);
  Serial.println("Zoek lijn");
  if(sensor1 > sensor1donker) Serial.println("Sensor 1 is zwart");
  if(sensor2 > sensor2donker) Serial.println("Sensor 2 is zwart");
  if(sensor3 > sensor3donker) Serial.println("Sensor 3 is zwart");
    int sCount = 0;
    if(sensor1 > sensor1donker) sCount++;
    if(sensor2 > sensor2donker) sCount++;
    if(sensor3 > sensor3donker) sCount++;
    if (sensor1 < sensor1donker && sensor3 < sensor3donker) {
        Serial.println("Moet nu rijden");
        motor(motor_rechts, 220, vooruit);
        motor(motor_links, 220, vooruit);
    } else if (sensor1 > sensor1donker && sensor3 < sensor3donker) { 
        Serial.println("Bocht naar links");
        motor(motor_rechts, 255, achteruit);
        motor(motor_links, 220, vooruit);
    } else if (sensor3 > sensor3donker && sensor1 < sensor1donker) {
        Serial.println("Bocht naar rechts");
        motor( motor_links, 255, achteruit);
        motor(motor_rechts, 220, vooruit);
    } else if ((sensor3 > sensor3donker && sensor1 > sensor1donker) || sCount >= 2) {
        Serial.println("You have reached your destination");
        opzoekNaarLijn = false;
        stastil();
        delay(2000);
        return true;
    }
    
    
    zoekReferentieLijn();
}


int scanAantal = 0;
boolean scanningDone = false;
boolean scanVeld() {
    if(scanAantal>5)
    {
      if(!scanningDone)
      {

        Serial.println(sensor1donker);
        Serial.println(sensor2donker);
        Serial.println(sensor3donker);
        rijd(3.5, achteruit, 255);
        opzoekNaarLijn = true;
        scanningDone = true;
      }
      return false;
    }
    scanAantal++;
    
    motor(motor_rechts, 255, vooruit);
    motor(motor_links, 255, vooruit);
    delay(500);

    sensor1 = analogRead(A0);
    sensor2 = analogRead(A1);
    sensor3 = analogRead(A2);
    if(sensor1licht==0)
    {
      sensor1licht = analogRead(A0);
      sensor2licht = analogRead(A1);
      sensor3licht = analogRead(A2);
    }
    if (sensor1 > sensor1donker){
      sensor1donker = sensor1;
    }
    if (sensor2 > sensor2donker){
      sensor2donker = sensor2;
    }
    if (sensor3 > sensor3donker){
      sensor3donker = sensor3;
    }
    return true;
    
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
    case 'X':
      schrijfx();
      break;
  }
}
void tiencmomhoog(int cijfer){
  motor(motor_links, 255, vooruit);
  motor(motor_rechts, 255, vooruit);
  //int teller=80; deze voor 10cm
  int teller = 230;
  for(int i = 0; i < teller; i++)
  {
    schrijfcijfer(cijfer);
    
  }
  dimmen();
}

void schrijfa(){
  //eerst draai
  draai(0.75, rechts);
  rijd(2);
  
  draai(1.5, links);
  rijd(2, achteruit);
  
  rijd(1);
  draai(1.1, links); 
  //Middelste streep
  rijd(1.5);
  draai(1.2, links); 
  rijd(1);
  draai(0.75, links);
}


void schrijfm(){
  //eerst streep recht omhoog
  rijd(2);
  // draai voor streep naar beneden
  draai(1, links); // -1
  rijd(1, achteruit);
  // draai voor streep naar boven
  draai(1.5, links);
  // lijn
  rijd(1, achteruit);
  // draai voor laatste lijn
  draai(1, links);
  // naar beneden rijden en done
  rijd(2);
}

void schrijfx() {
//eerst draai
  draai(1, rechts); // 1
  
  // Naar voren rijden
  rijd(2.5);
  // Dan naar achter
  rijd(1.25, achteruit);
  draai(2, rechts);
  
  rijd(1.25,achteruit);
  
  rijd(2.5,vooruit);
  
  draai(.75, rechts);

}

// Rijd voor of achteruit voor een bepaalde tijd in seconden
void rijd(float duur, boolean richting, byte power) {
    power = 255;
    motor(motor_rechts, power, richting);
     motor(motor_links,power,richting);
//    if(richting) {
//        motor(motor_links,power-40,richting);
//    } else{
//        motor(motor_links,power-45,richting);  
//    }
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
void draai(float duur, boolean richting, byte power) {
  motor(1, power, richting);
  motor(2, power,!richting);
  delay(duur*1000);
  stastil();
}

void draai(float duur, boolean richting) {
  byte power = 255;
  draai(duur, richting, power);
}

void draaiGraden(float graden, boolean richting) {

  byte power = 255;
  motor(1, power, richting);
  motor(2, power,!richting);
  
  delay(graden*18);
  
  stastil();
}

boolean checkbutton(){
 int buttonstate = analogRead(A3);
 if(buttonstate > 1020) {
  return true;
 } else {
  return false; 
 }
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
  delay(5);
  
  digitalWrite(3, HIGH); // GROUND
  digitalWrite(2, LOW); // GROUND
  switch (cijfer){
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
