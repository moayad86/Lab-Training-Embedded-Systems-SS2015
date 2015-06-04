


int inputDetectPin_5 = 5;
int inputDetectPin_6 = 6;
int inputDetectPin_7 = 7;

int OutputControlPin_2 = 2;
int OutputControlPin_3 = 3;
int OutputControlPin_4 = 4;
int OutputLedPin_8 = 8;
int OutputLedPin_9 = 9;
int OutputLedPin_10 = 10;
int OutputLedPin_11 = 11;

void setup() {
  pinMode(OutputControlPin_2, OUTPUT);
  pinMode(OutputControlPin_3, OUTPUT);
  pinMode(OutputControlPin_4, OUTPUT);
  pinMode(OutputLedPin_8, OUTPUT);
  pinMode(OutputLedPin_9, OUTPUT);
  pinMode(OutputLedPin_10, OUTPUT);
  pinMode(OutputLedPin_11, OUTPUT);

  pinMode(inputDetectPin_5, INPUT);
  pinMode(inputDetectPin_6, INPUT);
  pinMode(inputDetectPin_7, INPUT);
}

void loop() {

  //Reset all output Leds
  digitalWrite(OutputLedPin_8, LOW);
  digitalWrite(OutputLedPin_9, LOW);
  digitalWrite(OutputLedPin_10, LOW);
  digitalWrite(OutputLedPin_11, LOW);

  int TotalActive = 0; //To distinguish between NPN and PNP

  //Testing first pin
  digitalWrite(OutputControlPin_2, LOW);
  digitalWrite(OutputControlPin_3, HIGH);
  digitalWrite(OutputControlPin_4, HIGH);

  if (digitalRead(inputDetectPin_5) == HIGH)
  {
    TotalActive += 1;

    //Set output Leds
    digitalWrite(OutputLedPin_8, LOW);
    digitalWrite(OutputLedPin_9, HIGH);
    digitalWrite(OutputLedPin_10, HIGH);
  }

  //Testing second pin
  digitalWrite(OutputControlPin_2, HIGH);
  digitalWrite(OutputControlPin_3, LOW);
  digitalWrite(OutputControlPin_4, HIGH);

  if (digitalRead(inputDetectPin_6) == HIGH)
  {
    if (TotalActive == 0)
    {
      //Set output Leds
      digitalWrite(OutputLedPin_8, HIGH);
      digitalWrite(OutputLedPin_9, LOW);
      digitalWrite(OutputLedPin_10, HIGH);
    }

    TotalActive += 1;
  }

  //Testing third pin
  digitalWrite(OutputControlPin_2, HIGH);
  digitalWrite(OutputControlPin_3, HIGH);
  digitalWrite(OutputControlPin_4, LOW);

  if (digitalRead(inputDetectPin_7) == HIGH)
  {
    if (TotalActive == 0)
    {
      //Set output Leds
      digitalWrite(OutputLedPin_8, HIGH);
      digitalWrite(OutputLedPin_9, HIGH);
      digitalWrite(OutputLedPin_10, LOW);
    }

    TotalActive += 1;
  }

  //If TotalActive is more than one, meaning the transistor activated two times, then it's NPN, otherwise it's PNP
  if (TotalActive > 1)
  {
    digitalWrite(OutputLedPin_11, HIGH);
  }

}
