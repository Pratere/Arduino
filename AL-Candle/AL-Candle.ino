long int total1;
long int total2;
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
    for (int i=0; i<=200; i++){
      total1 += (analogRead(A0)/10); 
    }
    Serial.print(total1);
    state = 2;
    Serial.println();
  }
  if (state=2){
    total2=0;
    for (int i=0; i<=200; i++){
      total2 += (analogRead(A0)/10); 
    }
    state = 1;
    Serial.print(total2);
    Serial.println();
  }
  if (abs(total1-total2) > 75){
    digitalWrite(3, LOW);
    delay(2000);
    digitalWrite(3, HIGH);
  }
}
