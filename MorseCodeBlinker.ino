/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int mc[4]; // the current morse code char to 'display'
long dit = 25;
long dah = 250;
long dotInterval = 250;
long charInterval = 500;
long wordInterval = 750;

// the setup routine runs once when you press reset:
void setup() {         
  //Serial.begin(9600);  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  
  sendString("merry christmas");
  delay(1000);
}

void sendString(String text) {
  // split text into chars and send each
  for (int i=0; i<text.length(); i++) {
    Serial.print("Sending ");
    Serial.println(text[i]);
    sendChar(text[i]);
    delay(charInterval);
  }
}

void sendChar(char c) {
  // convert c to morse code
  charToMorse(c);
  
  Serial.print(c);
  Serial.print(": ");
  Serial.print(mc[0]);
  Serial.print("-");
  Serial.print(mc[1]);
  Serial.print("-");
  Serial.print(mc[2]);
  Serial.print("-");
  Serial.print(mc[3]);
  Serial.println("");
  Serial.print("sizeof(mc): ");
  Serial.println(sizeof(mc)-1);
  
  // send to LED
  for (int i=0; i<4; i++) {
    if(mc[i] > 0) {
      digitalWrite(led, HIGH);
      delay(mc[i]);
      digitalWrite(led, LOW);
      delay(dotInterval);
      Serial.print(mc[i]);
      Serial.print(".");
    }
  }
  Serial.println("");
}

int charToMorse(char c) {
  switch (c) {
    case 'a':
      mc[0] = dit;
      mc[1] = dah;
      mc[2] = 0;
      mc[3] = 0;
      break;
    case 'b':
      mc[0] = dah;
      mc[1] = dit;
      mc[2] = dit;
      mc[3] = dit;
      break;
    case 'c':
      mc[0] = dah;
      mc[1] = dit;
      mc[2] = dah;
      mc[3] = dit;
      break;
    case 'd':
      mc[0] = dah;
      mc[1] = dit;
      mc[2] = dit;
      mc[3] = 0;
      break;
    case 'e':
      mc[0] = dit;
      mc[1] = 0;
      mc[2] = 0;
      mc[3] = 0;
      break;
    case 'f':
      mc[0] = dit;
      mc[1] = dit;
      mc[2] = dah;
      mc[3] = dit;
      break;
    case 'g':
      mc[0] = dah;
      mc[1] = dah;
      mc[2] = dit;
      mc[3] = 0;
      break;
    case 'h':
      mc[0] = dit;
      mc[1] = dit;
      mc[2] = dit;
      mc[3] = dit;
      break;
    case 'i':
      mc[0] = dit;
      mc[1] = dit;
      mc[2] = 0;
      mc[3] = 0;
      break;
    case 'j':
      mc[0] = dit;
      mc[1] = dah;
      mc[2] = dah;
      mc[3] = dah;
      break;
    case 'k':
      mc[0] = dah;
      mc[1] = dit;
      mc[2] = dah;
      mc[3] = 0;
      break;
    case 'l':
      mc[0] = dit;
      mc[1] = dah;
      mc[2] = dit;
      mc[3] = dit;
      break;
    case 'm':
      mc[0] = dah;
      mc[1] = dah;
      mc[2] = 0;
      mc[3] = 0;
      break;
    case 'n':
      mc[0] = dah;
      mc[1] = dit;
      mc[2] = 0;
      mc[3] = 0;
      break;
    case 'o':
      mc[0] = dah;
      mc[1] = dah;
      mc[2] = dah;
      mc[3] = 0;
      break;
    case 'p':
      mc[0] = dit;
      mc[1] = dah;
      mc[2] = dah;
      mc[3] = dit;
      break;
    case 'q':
      mc[0] = dah;
      mc[1] = dah;
      mc[2] = dit;
      mc[3] = dah;
      break;
    case 'r':
      mc[0] = dit;
      mc[1] = dah;
      mc[2] = dit;
      mc[3] = 0;
      break;
    case 's':
      mc[0] = dit;
      mc[1] = dit;
      mc[2] = dit;
      mc[3] = 0;
      break;
    case 't':
      mc[0] = dah;
      mc[1] = 0;
      mc[2] = 0;
      mc[3] = 0;
      break;
    case 'u':
      mc[0] = dit;
      mc[1] = dit;
      mc[2] = dah;
      mc[3] = 0;
      break;
    case 'v':
      mc[0] = dit;
      mc[1] = dit;
      mc[2] = dit;
      mc[3] = dah;
      break;
    case 'w':
      mc[0] = dit;
      mc[1] = dah;
      mc[2] = dah;
      mc[3] = 0;
      break;
    case 'x':
      mc[0] = dah;
      mc[1] = dit;
      mc[2] = dit;
      mc[3] = dah;
      break;
    case 'y':
      mc[0] = dah;
      mc[1] = dit;
      mc[2] = dah;
      mc[3] = dah;
      break;
    case 'z':
      mc[0] = dah;
      mc[1] = dah;
      mc[2] = dit;
      mc[3] = dit;
      break;
  }
}

