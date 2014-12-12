#include <IRremote.h>

int irPin = 12;

IRrecv irrecv(irPin);

decode_results irResults;

bool isOn = HIGH;

int led1Pin = 3;//9;
int led2Pin = 5;//10;
int led3Pin = 6;//11;
int led4Pin = 9;//3;
int led5Pin = 10;//5;
int led6Pin = 11;//6;

bool isOn1 = HIGH;
bool isOn2 = LOW;
bool isOn3 = LOW;
bool isOn4 = LOW;
bool isOn5 = LOW;
bool isOn6 = LOW;

int button1Pin = 4;
int button2Pin = 5;
int button3Pin = 6;

int state1 = HIGH;      // the current state of the output pin
int reading1;           // the current reading from the input pin
int previous1 = LOW;    // the previous reading from the input pin

int state2 = HIGH;      // the current state of the output pin
int reading2;           // the current reading from the input pin
int previous2 = LOW;    // the previous reading from the input pin

int state3 = HIGH;      // the current state of the output pin
int reading3;           // the current reading from the input pin
int previous3 = LOW;    // the previous reading from the input pin

int state4 = HIGH;      // the current state of the output pin
int reading4;           // the current reading from the input pin
int previous4 = LOW;    // the previous reading from the input pin

int state5 = HIGH;      // the current state of the output pin
int reading5;           // the current reading from the input pin
int previous5 = LOW;    // the previous reading from the input pin

int state6 = HIGH;      // the current state of the output pin
int reading6;           // the current reading from the input pin
int previous6 = LOW;    // the previous reading from the input pin

int brightnessUpPin = 12;
int brightnessDownPin = 7;
int brightnessUpReading = 0;
int brightnessDownReading = 0;

int maxBrightnessLevel = 5;
int brightness = maxBrightnessLevel;

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

int command = 0;
int device = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);

  irrecv.enableIRIn(); // Start the receiver
}

// the loop function runs over and over again forever
void loop() {
  if (irrecv.decode(&irResults))
  {
    Serial.println(irResults.value);

    switch (irResults.value)
    {
      case 16753245:
      case 3810010651:
      case 93: // Power button
        Serial.println("Power button (remote)");
        isOn = !isOn;
        
        // If all channels are turned off but power is on then turn channel 1 on
        if (isOn == HIGH
          && isOn1 == LOW && isOn2 == LOW && isOn3 == LOW
          && isOn4 == LOW && isOn5 == LOW && isOn6 == LOW)
          isOn1 = HIGH;
        break;

      case 3855596927:
      case 16748655:
      case 154:
      case 111: // Brighter
        Serial.println("Brighter (remote)");
        if (brightness < maxBrightnessLevel)
          brightness = brightness + 1;
        break;

      case 16754775:
      case 2096480488:
      case 2747854299:
      case 87:
      case 56: // Dimmer
        Serial.println("Dimmer (remote)");
        if (brightness > 0)
          brightness = brightness - 1;
        break;

      case 2534850111:
      case 3517873801:
      case 16724175:
      case 207:
        Serial.println("Toggle one (remote)");
        if (isOn1 == HIGH)
          isOn1 = LOW;
        else
          isOn1 = HIGH;
        break;

      case 1247170601:
      case 1033561079:
      case 16718055:
      case 231:
        Serial.println("Toggle two (remote)");
        if (isOn2 == HIGH)
          isOn2 = LOW;
        else
          isOn2 = HIGH;
        break;

      case 3753866888:
      case 2197459858:
      case 1635910171:
      case 16743045:
      case 133:
        Serial.println("Toggle three (remote)");
        if (isOn3 == HIGH)
          isOn3 = LOW;
        else
          isOn3 = HIGH;
        break;

      case 2351064443:
      case 16716015:
        Serial.println("Toggle four (remote)");
        if (isOn4 == HIGH)
          isOn4 = LOW;
        else
          isOn4 = HIGH;
        break;

      case 16726215:
      case 1217346747:
        Serial.println("Toggle five (remote)");
        if (isOn5 == HIGH)
          isOn5 = LOW;
        else
          isOn5 = HIGH;
        break;

      case 1952287:
      case 16734885:
      case 71952287:
        Serial.println("Toggle six (remote)");
        if (isOn6 == HIGH)
          isOn6 = LOW;
        else
          isOn6 = HIGH;
        break;
    }

    irrecv.resume();
  }

  // TODO: Re-enable buttons

  /*reading1 = digitalRead(button1Pin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading1 == HIGH && previous1 == LOW && millis() - time > debounce) {
    if (state1 == HIGH)
      state1 = LOW;
    else
      state1 = HIGH;

    isOn1 = state1;

    time = millis();
  }

  reading2 = digitalRead(button2Pin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading2 == HIGH && previous2 == LOW && millis() - time > debounce) {
    if (state2 == HIGH)
      state2 = LOW;
    else
      state2 = HIGH;

    isOn2 = state2;
    time = millis();
  }

  reading3 = digitalRead(button3Pin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading3 == HIGH && previous3 == LOW && millis() - time > debounce) {
    if (state3 == HIGH)
      state3 = LOW;
    else
      state3 = HIGH;

    isOn3 = state3;
    time = millis();
  }*/

  /*
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading4 == HIGH && previous4 == LOW && millis() - time > debounce) {
    if (state4 == HIGH)
      state4 = LOW;
    else
      state4 = HIGH;

    isOn4 = state4;
    time = millis();
  }

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading5 == HIGH && previous5 == LOW && millis() - time > debounce) {
    if (state5 == HIGH)
      state5 = LOW;
    else
      state5 = HIGH;

    isOn5 = state5;
    time = millis();
  }


  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (reading6 == HIGH && previous6 == LOW && millis() - time > debounce) {
    if (state6 == HIGH)
      state6 = LOW;
    else
      state6 = HIGH;

    isOn6 = state6;
    time = millis();
  }*/

  /*brightnessUpReading = digitalRead(brightnessUpPin);
  brightnessDownReading = digitalRead(brightnessDownPin);

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (millis() - time > debounce) {
    if (brightnessUpReading && brightness < 5)
      brightness = brightness + 1;
    else if (brightnessDownReading && brightness > 0)
      brightness -=1;

    //  Serial.print("Brightness:");
    //  Serial.println(brightness);

    time = millis();
  }
  */
  int brightnessOutputValue = map(brightness, 0, maxBrightnessLevel, 0, 255);

  //Serial.print("Brightness value:");
  //Serial.println(brightnessOutputValue);
  /*Serial.print("On: ");
   Serial.print(isOn);
   Serial.print(" One: ");
   Serial.print(isOn1);
   Serial.print(" Two: ");
   Serial.print(isOn2);
   Serial.print(" Three: ");
   Serial.print(isOn3);
   Serial.println();*/

  if (isOn1 == HIGH && isOn == HIGH && brightness > 0)
    analogWrite(led1Pin, brightnessOutputValue);
  else
    analogWrite(led1Pin, LOW);

  if (isOn2 == HIGH && isOn == HIGH && brightness > 0)
    analogWrite(led2Pin, brightnessOutputValue);
  else
    analogWrite(led2Pin, LOW);

  if (isOn3 == HIGH && isOn == HIGH && brightness > 0)
    analogWrite(led3Pin, brightnessOutputValue);
  else
    analogWrite(led3Pin, LOW);

  if (isOn4 == HIGH && isOn == HIGH && brightness > 0)
    analogWrite(led4Pin, brightnessOutputValue);
  else
    analogWrite(led4Pin, LOW);

  if (isOn5 == HIGH && isOn == HIGH && brightness > 0)
    analogWrite(led5Pin, brightnessOutputValue);
  else
    analogWrite(led5Pin, LOW);

  if (isOn6 == HIGH && isOn == HIGH && brightness > 0)
    analogWrite(led6Pin, brightnessOutputValue);
  else
    analogWrite(led6Pin, LOW);

  delay(100);
}









