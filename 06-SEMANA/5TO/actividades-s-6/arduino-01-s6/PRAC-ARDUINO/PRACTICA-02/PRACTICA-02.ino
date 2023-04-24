int led2=9;
int led1=8;
int led0=7;
int tiempo1=150;
int tiempo2=80;
int tiempo3=250;
void setup() {
pinMode (led2, OUTPUT);
pinMode (led1, OUTPUT);
pinMode (led0, OUTPUT);
}
void loop() {
for (int s1=0; s1<13; s1++) {
digitalWrite (led2, LOW);
digitalWrite (led1, LOW);
digitalWrite (led0, HIGH);
delay (tiempo1);
digitalWrite (led2, LOW);
digitalWrite (led1, HIGH);
digitalWrite (led0, LOW);
delay (tiempo1);
digitalWrite (led2, HIGH);
digitalWrite (led1, LOW);
digitalWrite (led0, LOW);
delay (tiempo1);
}
for (int s2=0; s2<13; s2++) {
digitalWrite (led2, HIGH);
digitalWrite (led1, HIGH);
digitalWrite (led0, HIGH);
delay (tiempo2);
digitalWrite (led2, LOW);
digitalWrite (led1, LOW);
digitalWrite (led0, LOW);
delay (tiempo2);
}
for (int s3=0; s3<13; s3++) {
digitalWrite (led2, HIGH);
digitalWrite (led1, LOW);
digitalWrite (led0, LOW);
delay (tiempo1);
digitalWrite (led2, LOW);
digitalWrite (led1, HIGH);
digitalWrite (led0, LOW);
delay (tiempo1);
digitalWrite (led2, LOW);
digitalWrite (led1, LOW);
digitalWrite (led0, HIGH);
delay (tiempo1);
}
for (int s4=0; s4<13; s4++) {
digitalWrite (led2, HIGH);
digitalWrite (led1, HIGH);
digitalWrite (led0, LOW);
delay (tiempo3);
digitalWrite (led2, LOW);
digitalWrite (led1, HIGH);
digitalWrite (led0, HIGH);
delay (tiempo3);
digitalWrite (led2, HIGH);
digitalWrite (led1, LOW);
digitalWrite (led0, HIGH);
delay (tiempo3);
}
}

