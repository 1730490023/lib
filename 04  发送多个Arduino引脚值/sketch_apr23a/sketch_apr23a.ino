/*
 * 以二进制数据发送数值和模拟引脚值
 */

const char HEADER = 'H';  //提示一个消息的开始

void setup()
{
  Serial.begin(9600);
  for(int i = 2; i <= 13;i++)
  {
    pinMode(i,INPUT);       //设置引脚2到13为输入
    digitalWrite(i , HIGH); //打开上拉电阻 
  }
}

 void loop()
 {
   Serial.write(HEADER);    //发送信头
    int values = 0;          //把引脚的比特值转换为一个整数
    int bit = 0;
     for(int i=2; i<= 13; i++)
     {
      bitWrite(values,bit,digitalRead(i)); //根据给定引脚的值设置改位为0或1
      bit = bit+1;                         //递增到下一位
     }
      sendBinary(values);                   //发送整数
      for(int i =0;i <6;i++)
      {
        values = analogRead(i);
        sendBinary(values);                //发送整数
      }
      delay(50);                         //每秒发送一次
 }

void sendBinary(int values)      //将给定整数值发送到串口的函数
{                                 //发送组成整数的两字节
  Serial.write(lowByte(values));  //发送低字节
  Serial.write(highByte(values));  //发送高字节
}
   

