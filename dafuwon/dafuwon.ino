#include <SoftwareSerial.h>

const int TX = 4;
const int RX = 5;
const int LED = 13;
const int delaytime = 100;
int pos = 6;
const int maxpos = 13;
SoftwareSerial BT(RX, TX);
char val;

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  for (int i = 13; i >= 6; i--)
    pinMode(i, OUTPUT);
  for (int i = 1; i <= 1; i++)
    digitalWrite(pos, HIGH);
  pinMode(2, OUTPUT);
}

void loop()
{

  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW);
  delay(1000);

  if (BT.available())
  {
    val = BT.read();
    Serial.println(val);

    switch (val)
    {
    case '1':
      LEDflow(1);
      break;
    case '2':
      LEDflow(2);
      break;
    case '3':
      LEDflow(3);
      break;
    case '4':
      LEDflow(4);
      break;
    case '5':
      LEDflow(5);
      break;
    case '6':
      LEDflow(6);
      break;
    }
  }
}

void LEDflow(int a)
{
  int finalpos;
  int ifmax = 0;
  finalpos = pos + a;

  for (int i = pos; i <= finalpos - 1; i++)
  {
    if ((i + 1) > maxpos)
    {
      ifmax = 8;
      if (i == maxpos)
      {
        digitalWrite(maxpos, LOW);
        delay(delaytime);
      }
    }
    else
    {
      ifmax = 0;
    }

    digitalWrite(i - ifmax, LOW);
    delay(delaytime);
    digitalWrite(i + 1 - ifmax, HIGH);
    delay(delaytime);
  }
  pos = finalpos;
}

void LEDblink(int a)
{

  for (int i = 13; i >= 6; i--)
    digitalWrite(i, LOW);

  if ((pos + a) > maxpos)
  {
    int temp;
    temp = (pos + a) - maxpos;
    pos = 6 + temp - 1;
  }
  else
  {
    pos = pos + a;
  }
  digitalWrite(pos, HIGH);
}

