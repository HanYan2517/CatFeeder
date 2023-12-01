
int watersensor = 2;

void setup() {

  Serial.begin(9600);
  pinMode(watersensor, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int waterState = digitalRead(watersensor);
  // print out the state of the button:
  Serial.println(buttonState);
  delay(200);  // delay in between reads for stability
}
