int tim= 5;

int pinA  = 2;
int pinB  = 3;
int pinC  = 4;
int pinD  = 5;
int pinE  = 6;
int pinF  = 7;
int pinG  = 8;

int x = 0;
int input = A0;
int state = 0;


int DIG1 = 12;
int DIG2 = 11;
int DIG3 = 10;
int DIG4 = 9;

void choose_digit(char num){
  
  switch(num){
    default:
    // 0 default value;

      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;

    case 1:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 2:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 3:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;

    case 4:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 5:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 6:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 7:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;

    case 8:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;

    case 9:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
    }
  
  
  }

void setup() {
  pinMode(input, INPUT);
  
  pinMode(DIG1, OUTPUT);
  pinMode(DIG2, OUTPUT);
  pinMode(DIG3, OUTPUT);
  pinMode(DIG4, OUTPUT);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  
  
  Serial.begin(9600);
}

void pick_digit(int digit){
  digitalWrite(DIG1, LOW);
  digitalWrite(DIG2, LOW);
  digitalWrite(DIG3, LOW);
  digitalWrite(DIG4, LOW);

  switch(digit){
    case 1:digitalWrite(DIG1, HIGH);break;
    case 2:digitalWrite(DIG2, HIGH);break;
    case 3:digitalWrite(DIG3, HIGH);break;
    default:digitalWrite(DIG4, HIGH);break;
  }
}

void seven_segment(int number){
  unsigned char thousands  = int (number/1000);
  unsigned char hundreds   = int ((number/100)%10);
  unsigned char tens       = int ((number/10)%10);
  unsigned char ones       = int (number%10);
  
  //1234
  choose_digit(thousands);
  pick_digit(1);
  delay(tim);

  choose_digit(hundreds);
  pick_digit(2);
  delay(tim);

  choose_digit(tens);
  pick_digit(3);
  delay(tim);

  choose_digit(ones);
  pick_digit(4);
  delay(tim);
}

void loop() {
  seven_segment(x-1);
  
  int counter = digitalRead(A0);
    
  if (state == 0)
  {
    switch (counter) {

      case 1 : state = 1; x = x + 1; break;
      case 0 : state = 0; break;

    }
  }

  if (counter == LOW) {
    state = 0;
  }
   
  delay(1);
}
