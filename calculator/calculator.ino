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
    {'1', '2', '3', '/'},
    {'4', '5', '6', '*'},
    {'7', '8', '9', '-'},
    {'c', '0', '=', '+'}};
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  // TODO: put your setup code here, to run once:
  Wire.begin(400); // IIC 总线启动
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2, 0); // 例程中没有，不可省略，否者第二行无法显示----------------------------------------------

  Serial.begin(9600);
  while (Serial.read() >= 0)
  {
  } // clear serialbuffer
  Serial.println("Serial Test ... ...");

  lcd.setCursor(0, 0);
  lcd.print("Please waiting..");
  delay(1000);
  lcd.setCursor(0, 1); // 0-列、1-行
  lcd.print("Now u can enter!");
  delay(2000);
  lcd.clear();
  // lcd.begin(16,2,0);
}

boolean firstNumState = true; // 判断true输入第一个数，还是false第二个数
float firstNum = 0.0;         // 用于接收键盘输入的第一个数
String key_String = "";       // 用于接收键盘输入字符串，将用于转换成数字
int dispNum = 0;              // 用于输出不含小数位的数
float secondNum = 0.0;        // 用于接收键盘输入的第二个数
float result = 0.0;           // 用于运算结果
char operatr = ' ';           // 用于接收键盘输入的运算符
void loop()
{
  // TODO: put your main code here, to run repeatedly:

  char newKey = myKeypad.getKey();

  if (newKey != NO_KEY && (newKey == '1' || newKey == '2' || newKey == '3' || newKey == '4' || newKey == '5' || newKey == '6' || newKey == '7' || newKey == '8' || newKey == '9' || newKey == '0'))
  {
    if (firstNumState == true)
    {
      key_String = newKey;
      firstNum = firstNum * 10 + key_String.toFloat(); // 将连续输入的单个数字转换成一个完整的数
      dispNum = firstNum;
      Serial.print(newKey);
      lcd.setCursor(1, 0); // 在第一排前半部打印第一个数
      lcd.print(dispNum);  // 直接打印float会有小数点，而键盘输入时没有小数点，所以用一个整数来接收再打印
      dispNum = 0;
      key_String = "";
    }
    else
    {

      key_String = newKey;
      secondNum = secondNum * 10 + key_String.toFloat(); // 将连续输入的单个数字转换成一个完整的数
      dispNum = secondNum;
      Serial.print(newKey);
      lcd.setCursor(9, 0); // 在第二排前半部打印第二个数
      lcd.print(dispNum);
      dispNum = 0;
      key_String = "";
    }
  }
  if (newKey != NO_KEY && (newKey == '+' || newKey == '-' || newKey == '*' || newKey == '/'))
  {
    if (firstNumState == true)
    {
      operatr = newKey;
      firstNumState = false;
      Serial.print(newKey);
      lcd.setCursor(8, 0); // 在第一排前中间打印操作符
      lcd.print(operatr);
    }
  }
  if (newKey != NO_KEY && newKey == '=')
  {
    if (operatr == '+')
    {
      result = firstNum + secondNum;
    }
    if (operatr == '-')
    {
      result = firstNum - secondNum;
    }
    if (operatr == '*')
    {
      result = firstNum * secondNum;
    }
    if (operatr == '/')
    {
      result = firstNum / secondNum;
    }
    Serial.print(newKey);
    dispNum = result;

    lcd.setCursor(1, 1); // 在第二排打印输出结果
    lcd.print("=");
    if (operatr == '/')
    {
      lcd.print(result); // 产生小数位则打印float类型的数字
      Serial.println(result);
    }
    else
    {
      lcd.print(dispNum); // 不产生小数位则打印int类型的数字
      Serial.println(dispNum);
    }

    firstNumState = true;
    dispNum = 0;
  }

  if (newKey != NO_KEY && newKey == 'c')
  {
    firstNum = 0;
    secondNum = 0;
    result = 0;
    operatr = ' ';
    firstNumState = true;
    Serial.println(newKey);
    lcd.clear();
  }
}
