int sensor1licht = analogRead(A0);
int sensor2licht = analogRead(A1);
int sensor3licht = analogRead(A2);
int sensor1donker;
int sensor2donker;
int sensor3donker;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
  sensor1licht = analogRead(A0);
  sensor2licht = analogRead(A1);
  sensor3licht = analogRead(A2);
}

void loop() {
//  read the input on analog pin 0:
//  int sensorValue1 = analogRead(A0);
//  int sensorValue2 = analogRead(A1);
//  int sensorValue3 = analogRead(A2);
int sensor1donker;
int sensor2donker;
int sensor3donker;

if (sensor1licht > sensor1donker){
  sensor1donker = sensor1licht;
}
if (sensor2licht > sensor2donker){
  sensor2donker = sensor2licht;
}
if (sensor3licht > sensor3donker){
  sensor3donker = sensor3licht;
}

  
//  // print out the value you read:
//  Serial.println(sensorValue1);
//  Serial.println("Sensor 1");
//  delay(1000);
//  Serial.println(sensorValue2);
//  Serial.println("Sensor 2");
//  delay(1000);
//  Serial.println(sensorValue3);
//  Serial.println("Sensor 3");
//  delay(1000);  

//Sensor1 waardes ong 600-700. ongeveer > 800 wanneer op iets zwarts. (750 zou ook moeten werken)
//Sensor2 werkt niet heel goed, waardes rond 850 constant, tenzij dicht bij de grond. (ook op zwart) (als middelste gebruiken en wat dichter bij de grond hangen?) >850 moet werken
//Sensor3 650-750 waardes op zwart >800

//    if (Sensor1 < 750 && Sensor3 < 800) {
//      motor(1, motorrechts, vooruit);
//        motor(2, motorlinks, vooruit);
//    } else if (Sensor1 > 750 && Sensor3 < 800){
//      while (Sensor3 < x){
//        motor(2, 0);
//      }
//    } else if (Sensor3 < 800 && Sensor1 > 750) {
//      while (Sensor1 > x){
//        motor(1, 0);
//      }
//    } else if (Sensor 3 > 800 && Sensor1 >750) {
//        stastil();
      }
//
//void loop(){
//  rijd(1);
//  draai(2, links);
//  if(Sensor2 > 850){
//    rijd
//  }

  
//}




