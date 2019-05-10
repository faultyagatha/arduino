const int input_pin = 3;

const int potent_meter1 = 5;
const int potent_meter2 = 4;
const int potent_meter3 = 3;

const int output_green_led = 5;
const int output_red_led = 6;

void setup() {
  pinMode(input_pin, INPUT);
  Serial.begin(9600);

  pinMode(potent_meter1, INPUT);
  pinMode(potent_meter2, INPUT);
  pinMode(potent_meter3, INPUT);

  pinMode(output_green_led, OUTPUT);
  pinMode(output_red_led, OUTPUT);

}

void loop() {
  int value = digitalRead(input_pin);
  Serial.println(value); //serial = usb

  int value1 = analogRead(potent_meter1);
  Serial.println(value1); //serial = usb

  int value2 = analogRead(potent_meter2);
  Serial.println(value2); //serial = usb

  int value3 = analogRead(potent_meter3);
  Serial.println(value3); //serial = usb
  //  delay(1000);


  if (value == 0) {
    if (value3 < 512) {
      if (value1 < 512) {
        digitalWrite(output_green_led, 0);
      } else {
        digitalWrite(output_green_led, 1);
      }
      if (value2 < 512) {
        digitalWrite(output_red_led, 0);
      } else {
        digitalWrite(output_red_led, 1);
      }
    } else {
      digitalWrite(output_green_led, 0);
      digitalWrite(output_red_led, 0);
    }
  } else {
    digitalWrite(output_green_led, 0);
    digitalWrite(output_red_led, 0);
  }
}
