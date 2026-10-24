#include <DabbleESP32.h>
#define INCLUDE_GAMEPAD_MODULE


#define ENA 5
#define IN1 19
#define IN2 23 

#define ENB 18
#define IN3 15
#define IN4 4

#define JN3 27
#define JN4 13
#define JNA 14

#define JNB 26
#define JN1 25
#define JN2 33


void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(JNA, OUTPUT);
  pinMode(JN3, OUTPUT);
  pinMode(JN4, OUTPUT);

  pinMode(JNB, OUTPUT);
  pinMode(JN1, OUTPUT);
  pinMode(JN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  

  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  digitalWrite(JNA, HIGH);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  digitalWrite(JN3, LOW);
  digitalWrite(JN4, LOW);

  digitalWrite(JN1, LOW);
  digitalWrite(JN2, LOW);

  Dabble.begin("G's Crop Bot");
}

void loop() {
  Dabble.processInput();

  if (GamePad.isUpPressed()){
    forward();
  }
  else if(GamePad.isDownPressed()){
    backward();
  }
  else if(GamePad.isLeftPressed()){
    left();
  }
  else if(GamePad.isRightPressed()){
    right();
  }
  else if(GamePad.isTrianglePressed()){
    triangle();
  }
  else{
    stopMotors();
  }

}


  void forward(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }

  void backward(){
    
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  void left(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

    void right(){
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }

   void stopMotors(){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    digitalWrite(JN3, LOW);
    digitalWrite(JN4, LOW);

    digitalWrite(JN1, LOW);
    digitalWrite(JN2, LOW);

  }

   void triangle(){
    digitalWrite(JN3, LOW);
    digitalWrite(JN4, HIGH);

    digitalWrite(JN1, LOW);
    digitalWrite(JN2, HIGH);

  }
