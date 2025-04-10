int default_led_pin = 2;
void setup()
{
  pinMode(default_led_pin, OUTPUT);
}
void loop()
{
  digitalWrite(default_led_pin, HIGH);
  delay(500);
  digitalWrite(default_led_pin, LOW);
  delay(500);
}
