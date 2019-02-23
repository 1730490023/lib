/*
 * led闪烁的速度正比与所接收到的数字值
 */
const int ledpin = 13;
int blinkrate = 0;
void setup() {
  Serial.print(9600);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  blink();
}

void serialevent()
{
  while(Serial.available())
  {
    char ch = Serial.read();
    Serial.write(ch);
    if( isDigit(ch))
    {
      blinkrate = (ch - '0');
      blinkrate = blinkrate * 100;
    }
  }
}

void blink()
{
  digitalWrite(ledpin,HIGH);
  delay(blinkrate);
  digitalWrite(ledpin,LOW);
  delay(blinkrate);
}

