const int enA = 9;
const int in1 = 4;
const int in2 = 5;
const int enB = 10;
const int in3 = 6;
const int in4 = 7;
const int echoPin1 = 11;
const int trigPin1 = 12;
const int trigPin2 = 13;
const int echoPin2 = 8;

long duration;
long distance;
int motorASpeed = 0;
int motorBSpeed = 0;
int Speed = 180;
int targetRightDistance = 7;
int aggressiveness = 20;

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  turning();
}

void loop() {
  //hungTheWall();
  
  
  

  // Y-axis used for forward and backward control
  
  if (getDistance(trigPin1, echoPin1) > 6 && getDistance(trigPin2, echoPin2) < 9){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 160);
    analogWrite(enB, 260);
    delay(750);
    analogWrite(enA, 260);
    analogWrite(enB, 160);
    delay(300);
  }
  else if (getDistance(trigPin1, echoPin1) > 6 && (getDistance(trigPin2, echoPin2) > 11 || getDistance(trigPin2, echoPin2) < 14)) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 260);
    analogWrite(enB, 160);
    delay(750);
    analogWrite(enA, 160);
    analogWrite(enB, 260);
    delay(300);
    
  }
  else if (getDistance(trigPin1, echoPin1) > 6 && getDistance(trigPin2, echoPin2) >= 400){
    delay(500);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 240);
    analogWrite(enB, 240);
    delay(2500);
  }
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    else{
  // }     // Set Motor A forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    delay(500);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 240);
    analogWrite(enB, 240);
    delay(2500);

    }
    analogWrite(enA, motorASpeed);
    analogWrite(enB, motorBSpeed);
  
    // Convert the increasing Y-axis readings for going forward from 550 to 1023 into 0 to 255 value for the PWM signal for increasing the motor speed
    
  }
 

int getDistance(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  
  distance = duration/74/2;
  return distance;
}

void hungTheWall(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
    // Set Motor B backward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, Speed);
  analogWrite(enB, Speed+(targetRightDistance - getDistance(trigPin2, echoPin2))*aggressiveness);
}

void turning(){
  int tick = 0;  
  int distance = 0;
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 160);
  analogWrite(enB, 160);
  while(distance < 170){
    distance = getDistance(trigPin1, echoPin1);
    tick++;
    Serial.println("distance");
    Serial.println(distance);
    Serial.println("tick");
    Serial.println(tick);
  }
  while(tick > 0)
  {
    --tick; 
    delay(5);
    Serial.println("tick minus");
    Serial.println(tick);   
  }
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}




