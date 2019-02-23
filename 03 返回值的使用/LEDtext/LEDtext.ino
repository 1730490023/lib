/*
 * 这个程序将演示如何使用带参数的函数，并返回一个值。
 * 程序启动时LED开始闪烁，当当开光被按下时停止，
 * 然后程序将打印LED闪烁的次数。
 */
const int ledpin = 13;
const int inputpin = 2;

void setup() {
  pinMode(ledpin,OUTPUT);
  pinMode(inputpin,INPUT);
  digitalWrite(inputpin,HIGH);          //使用内部的上拉电阻
  Serial.begin(9600);

}

void loop() {
  //Serial.print("/n press and hold the switch to stop blinking \n");
  int count = blink3(500);            //将子函数的返回值赋给count
  Serial.print("the number of times the switch blinked was  ");
  Serial.print(count);                //打印出LED闪烁的次数
  Serial.print("  \n");
}

int blink3(int period)
{
  int result = 0;
  int switchval = HIGH;               

  while(switchval ==  HIGH)                 
  {
    digitalWrite(13,HIGH);
    delay(period);
    digitalWrite(13,LOW);
    delay(period);
    result = result + 1;                     //增加count
    switchval = digitalRead(inputpin);       //读取D2口的输入值
  }
  return result;
}





