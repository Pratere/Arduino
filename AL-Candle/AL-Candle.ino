int total1;
int total2;
int state=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (state=1){
    total1=0;
    for (int i=0; i>=200; i++){
      total1 += analogRead(A0); 
    }
    state = 2;
  }
  if (state=2){
    total2=0;
    for (int i=0; i>=200; i++){
      total2 += analogRead(A0); 
    }
    state = 1;
  }
  if (abs(total1-total2) > 100){
    digitalWrite(3, LOW);
  }
}
