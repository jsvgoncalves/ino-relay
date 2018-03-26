/**
 * Light up a lamp with a relay, using serial communication.
 */
int pin = 8;
String in = "";
boolean done = false;

void setup() {
  Serial.begin(9600);
  in.reserve(200);
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}

void loop() {
  if (done) {
    if(in == "on\n") {
      Serial.println("ON");
      digitalWrite(pin, HIGH);
    } else {
      Serial.println("OFF");
      digitalWrite(pin, LOW);
    }
    in = "";
    done = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char in_c = (char)Serial.read();
    in += in_c;
    if (in_c == '\n') {
      done = true;
    }
  }
}
