#include <TimerOne.h>

#define OUT  2
#define S2   10
#define S3   11
#define S0   8
#define S1   9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(OUT, INPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(S0, LOW);    // 2% of Output Frequency Range
  digitalWrite(S1, HIGH);
  int R=0;
  int G=0;
  int B=0;
  int W=0;
  int phi=analogRead(A0);

  //Red
  digitalWrite(S2, LOW);    
  digitalWrite(S3, LOW);
  Timer1.setPeriod(10000);
  while(digitalRead(OUT)==1){
    R++;
    break;
  }

  //Green
  digitalWrite(S2, HIGH);    
  digitalWrite(S3, HIGH);
  Timer1.setPeriod(10000);
  while(digitalRead(OUT)==1){
    G++;
    break;
  }

  //Blue
  digitalWrite(S2, LOW);    
  digitalWrite(S3, HIGH);
  Timer1.setPeriod(10000);
  while(digitalRead(OUT)==1){
    B++;
    break;
  }
  
  //White
  digitalWrite(S2, HIGH);    
  digitalWrite(S3, LOW);
  Timer1.setPeriod(10000);
  while(digitalRead(OUT)==1){
    W++;
    break;
  }
  
  Serial.print(millis());
  Serial.print(",");
  Serial.print(phi);
  Serial.print(",");
  Serial.print(W);
  Serial.print(",");
  Serial.print(R);
  Serial.print(",");
  Serial.print(G);
  Serial.print(",");
  Serial.println(B);
}
