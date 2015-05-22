
int InputPin_7 = 7;

int OutputPin_6 = 6;
int OutputPin_8 = 8;
int OutputPin_9 = 9;

void setup() {
  pinMode(InputPin_7, INPUT);
  pinMode(OutputPin_8, OUTPUT);
  pinMode(OutputPin_6, OUTPUT);
  pinMode(OutputPin_9, OUTPUT);
}

void loop() {
  digitalWrite(OutputPin_8, LOW);
  digitalWrite(OutputPin_9, LOW);
  digitalWrite(OutputPin_6, LOW);
  
  if (digitalRead(InputPin_7) == LOW)
  {
    digitalWrite(OutputPin_6, HIGH);
    if (digitalRead(InputPin_7) == HIGH)
    {
      //Transistor
      digitalWrite(OutputPin_9, HIGH);
      digitalWrite(OutputPin_8, LOW);
    }
    //else - nothing detected
  }
  else
  {
    //Diode
    digitalWrite(OutputPin_8, HIGH);
    digitalWrite(OutputPin_9, LOW);
  }
}
