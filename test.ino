//WHEEL 1
const int motor1pin1 = 10;
const int motor1pin2 = 11;

//WHEEL 2
const int motor2pin1 = 12;
const int motor2pin2 = 13;

//8 Sensor IR
int sensors[10];




void input_sensors(){
  for(int i=2; i<=9; i++){
    sensors[i]=digitalRead(i);
  }
}

void forward(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}


void backward(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void soft_right(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}


void soft_left(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}


void hard_left(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}


void hard_right(){
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void stopmotion(){
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}


void setup(){
  //set pins as output
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);  
}

String value(){
  String s="";
  for(int i=2; i<=9; i++){
    s+=(char)(sensors[i]+'0');
  }
  return s;
}

void loop(){
  input_sensors();
  String v=value();

  int sum_left=0, sum_right=0;
  for(int i=2; i<=5; i++) sum_left+=sensors[i];
  for(int i=6; i<=9; i++) sum_right+=sensors[i];
  if(v=="11111111")
  {
    forward();
  }else if(v=="00000000"){
    forward();   
  }
  else if(sum_left>sum_right) soft_right();
  else if(sum_left<sum_right) soft_left();
  else forward();
}
