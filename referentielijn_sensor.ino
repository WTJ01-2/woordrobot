int Sensor1 = analogRead(A0);
int Sensor2 = analogRead(A1);
int Sensor3 = analogRead(A2);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {
//Sensor1 waardes ong 600-700. ongeveer > 800 wanneer op iets zwarts. (750 zou ook moeten werken)
//Sensor2 werkt niet heel goed, waardes rond 850 constant, tenzij dicht bij de grond. (ook op zwart) (als middelste gebruiken en wat dichter bij de grond hangen?) >850 moet werken
//Sensor3 650-750 waardes op zwart >800

    if (Sensor1 < 750 && Sensor3 < 800) {
      motor(1, motorrechts, vooruit);
        motor(2, motorlinks, vooruit);
    } else if (Sensor1 > 750 && Sensor3 < 800){
      while (Sensor3 < x){
        motor(2, 0);
      }
    } else if (Sensor3 < 800 && Sensor1 > 750) {
      while (Sensor1 > x){
        motor(1, 0);
      }
    } else if (Sensor 3 > 800 && Sensor1 >750) {
        stastil();
    }

void loop(){
  rijd(1);
  draai(2, links);
  if(Sensor2 > 850){
    rijd(1.5);
  }

  
}




