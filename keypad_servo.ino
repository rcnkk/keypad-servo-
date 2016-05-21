#include <Keypad.h>
#include <Servo.h>
byte servopin = 3;
const byte satir = 4;
const byte sutun = 4;
String deger = "";
char tus;
char tus_takimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte satir_pinleri[satir] = {12, 11, 10, 9};
byte sutun_pinleri[sutun] = {8, 7, 6, 5};

Keypad a = Keypad(makeKeymap(tus_takimi) , satir_pinleri , sutun_pinleri , satir , sutun);
Servo servo1;
void setup()
{ servo1.attach(servopin);
  Serial.begin(9600);
}

void loop()
{
  tus = a.getKey();
  if (tus)
  {
    deger += tus;
    int z = deger.toInt();
    if (tus == '#') {
      servo1.write(z);
      deger = "";
    }
  }

}
