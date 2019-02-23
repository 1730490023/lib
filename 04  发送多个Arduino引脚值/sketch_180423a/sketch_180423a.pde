import processing.serial.*;

Serial myPort;                //创建一个串口类对象
short portIndex = 0;

char HEADER = 'H';

void setup()
{
  size(200,200);
  String portName = Serial.list()[portIndex];  //打开Arduino的串口
  printArray(Serial.list());
  println("Connecting to ->" + Serial.list()[portIndex]);
  myPort = new Serial(this ,portName, 9600); 
}

void draw()
{
 int val;
  
  if(myPort.available() >=15)        //等待整个消息到达
  {
   if(myPort.read() == HEADER)       //这是信头
   {
      println("message received");
      //发现信头
      //获得包含比特值的整数
      val = readArduinoInt();
      
      for(int pin=2,bit=1;pin<=13;pin++) //打印每一位的值
      {
        print("digital pin" + pin + "=");
        int isSet = (val & bit);
        if( isSet == 0)
        {
          println("0");
        }
        else
        {
         println("1");
        }
        bit = bit*2;      //位移到下一个更高的二进制位
      }
      
      println();
      for(int i=0;i<6;i++)  //打印6个模拟值
      {
       val = readArduinoInt();
       println("analog port " + i + "=" +val);
      }
      println("------");  
   } 
  }
}
  
//根据串口接收到的字节返回整型值  
  
int readArduinoInt()
{
  int val;               //从串口收到的数据
  val = myPort.read();   //读取最小显著性字节
  val = myPort.read() * 256 + val;  //加上最大显著性字节
  return val;
}
