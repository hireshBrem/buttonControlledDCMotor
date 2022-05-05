int speedPin = 3;
int motorSpeed;
int dir1Pin = 2;
int dir2Pin = 4;
int dt = 250;
int posPin = 12;
int negPin = 13;
int posVal;
int negVal;

void setup() {
  Serial.begin(9600);
  pinMode(speedPin, OUTPUT);
  pinMode(dir1Pin, OUTPUT);
  pinMode(dir2Pin, OUTPUT);
  pinMode(posPin, OUTPUT);
  pinMode(negPin, OUTPUT);
  digitalWrite(posPin, HIGH);
  digitalWrite(negPin, HIGH);
}

void loop() {
  Serial.print("The posPin: ");
  posVal = digitalRead(posPin);
  Serial.println(posVal);
  delay(dt);
  Serial.print("The negPin: ");
  negVal = digitalRead(negPin);
  Serial.println(negVal);
  delay(dt);
    
  if(posVal == 0){
    motorSpeed+=30;
  }
  
  if(negVal == 0){
    motorSpeed-=30;
  }

  if(motorSpeed<0){
    analogWrite(speedPin, motorSpeed*(-1));  
    digitalWrite(dir1Pin, HIGH);
    digitalWrite(dir2Pin, LOW);
  }
  
  if(motorSpeed>255){
    motorSpeed = 255;
  }

  if(motorSpeed>0 && motorSpeed<255) {
    analogWrite(speedPin, motorSpeed);  
    digitalWrite(dir1Pin, LOW);
    digitalWrite(dir2Pin, HIGH);
  }
  
  Serial.print("The motor speed is: ");
  Serial.println(motorSpeed);
}
