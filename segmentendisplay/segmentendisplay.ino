int buttonstate = 0;
void setup()
{
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  //Serial.begin(9600);
}

void loop()
{
    buttonstate = analogRead(A0);
     if(buttonstate > 1020){
       schrijfcijfer(1);
     } else{
       schrijfcijfer(0);
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
   
 

