#include <RDA5807.h>
#include <Key.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const byte ROWS = 4;
const byte COLS = 4;
byte rowPins[ROWS] = {11, 10, 9, 8}; // 按键端口号
byte colPins[COLS] = {7, 6, 5, 4};   // 按键端口号
char keys[ROWS][COLS] = {            // 按键编码
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'.', '0', '=', 'D'}};
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
RDA5807 rx;
bool checkI2C()
{
  Wire.begin();
  byte error, address;
  int nDevices;
  Serial.println("I2C bus Scanning...");
  nDevices = 0;
  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0)
    {
      Serial.print("\nI2C device found at address 0x");
      if (address < 16)
      {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("\nUnknow error at address 0x");
      if (address < 16)
      {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0)
  {
    Serial.println("No I2C devices found\n");
    return false;
  }
  else
  {
    Serial.println("done\n");
    return true;
  }
}

void setup()
{
  Wire.begin(400); // IIC 总线启动
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2, 0); // 例程中没有，不可省略，否者第二行无法显示----------------------------------------------
  Serial.begin(9600);
  while (Serial.read() >= 0)
  {
  } // clear serialbuffer
  Serial.println("Serial Test ... ...");
  lcd.clear();
  while (!Serial)
    ;
  delay(50);
  if (!checkI2C())
  {
    Serial.println("\nCheck your circuit!");
    while (1)
      ;
  }
  rx.setup();
  rx.setVolume(3);

  //****
  Serial.print("\nEstacao 106.5MHz");
  rx.setFrequency(10650); // The frequency you want to select in MHz multiplied by 100.

  Serial.print("\nCurrent Channel: ");
  Serial.print(rx.getRealChannel());

  Serial.print("\nReal Frequency.: ");
  Serial.print(rx.getRealFrequency());

  Serial.print("\nRSSI: ");
  Serial.println(rx.getRssi());

  lcd.setCursor(0, 0);
  lcd.print("Please waiting..");
  delay(100);
  lcd.setCursor(0, 1); // 0-列、1-行
  lcd.print("Now u can enter!");
  delay(200);
  lcd.clear();
}
boolean firstNumState = true; // 判断true输入第一个数，还是false第二个数
boolean pointstate = false;
int channelA = 10450;
int channelB = 10340;
int channelC = 9860;
int channelD = 9210;
double point = 0.0;
double firstNum = 0; // 用于接收键盘输入的第一个数
int frenum = 0;
String key_String = ""; // 用于接收键盘输入字符串，将用于转换成数字
int dispNum = 0;        // 用于输出不含小数位的数
void loop()
{
  char newKey = myKeypad.getKey();
  if (newKey != NO_KEY && (newKey == '.' || newKey == '1' || newKey == '2' || newKey == '3' || newKey == '4' || newKey == '5' || newKey == '6' || newKey == '7' || newKey == '8' || newKey == '9' || newKey == '0'))
  {
    lcd.setCursor(0, 0); 
    if (firstNumState)
    {
      lcd.clear();
      pointstate = false;
    }
    firstNumState = false;
    if (newKey == '.')
    {
      pointstate = true;
    }
    else
    {
      if (pointstate == false)
      {
        key_String = newKey;
        firstNum = firstNum * 10 + key_String.toFloat(); // 将连续输入的单个数字转换成一个完整的数
      }
      else
      {
        key_String = newKey;
        point = key_String.toFloat() / 10;
        firstNum = firstNum + point;
      }
    }
    Serial.print(newKey);
    lcd.print("TO:");
    lcd.print(firstNum);

    key_String = "";
  }
  if (newKey != NO_KEY && newKey == '=')
  {
    if (firstNum == 0)
    {
      lcd.clear();
    }
    else
    {
      Serial.print("\nChange the channel:");
      frenum = int(firstNum * 100);
      Serial.println(frenum);
      rx.setFrequency(frenum);
      lcd.setCursor(0, 0);
      lcd.print("Change channel:");
      lcd.setCursor(0, 1); // 0-列、1-行
      lcd.print("FM");
      lcd.print(firstNum);
      
    }
      firstNum = 0;
      firstNumState = true;
  }

  if (newKey != NO_KEY && newKey == 'A')
  {
    lcd.clear();
    firstNumState = true;
    frenum = 10450;
    Serial.print("\nChange the channel:");
    Serial.println(channelA);
    rx.setFrequency(channelA);
      lcd.setCursor(0, 0);
    lcd.print("Channel A :");
    lcd.setCursor(0, 1); // 0-列、1-行
    lcd.print("FM");
    float f = float(channelA)/100;
    lcd.print(f);
  }
  if (newKey != NO_KEY && newKey == 'B')
  {
    lcd.clear();
    firstNumState = true;
    frenum = 10340;
    Serial.print("\nChange the channel:");
    Serial.println(channelB);
    Serial.println("Shenyang News Broadcast: 104.5MHz");
    rx.setFrequency(channelB);
     lcd.setCursor(0, 0);
    lcd.print("Channel B :");
    lcd.setCursor(0, 1); // 0-列、1-行
    lcd.print("FM");
    float f = float(channelB)/100;
    lcd.print(f);
  }
  if (newKey != NO_KEY && newKey == 'C')
  {
    lcd.clear();
    firstNumState = true;
    frenum = 9860;
    Serial.print("\nChange the channel:");
    Serial.println(channelC);
    Serial.println("Shenyang News Broadcast: 104.5MHz");
    rx.setFrequency(channelC);
    lcd.setCursor(0, 0);
    lcd.print("Channel C :");
    lcd.setCursor(0, 1); // 0-列、1-行
    lcd.print("FM");
    float f = float(channelC)/100;
    lcd.print(f);
  }
  if (newKey != NO_KEY && newKey == 'D')
  {
    lcd.clear();
    firstNumState = true;
    frenum = 9210;
    Serial.print("\nChange the channel:");
    Serial.println(channelD);
    Serial.println("Shenyang News Broadcast: 104.5MHz");
    rx.setFrequency(channelD);
      lcd.setCursor(0, 0);
    lcd.print("Channel D :");
    lcd.setCursor(0, 1); // 0-列、1-行
    lcd.print("FM");
    float f = float(channelD)/100;
    lcd.print(f);
  }
}
