
#define btn_num 5
int btn [btn_num] = {9, A0, A1, A2, 2};
bool btn_old_sg [btn_num] = {1, 1, 1, 1, 1};
int floor_steps = 1280;
/*
    زر طابق الاول a0
  2 = A1
  3 = A3
  4 = 9
  Ssami
  Ssami Abdou
  Ir 3
*/
void btnSetup()
{
  // Bouton poussoir 1
  for (int i = 0; i < btn_num ; i++) {
    pinMode(btn[i], INPUT_PULLUP);
  }

}

void btnLoop()
{
  // Si Appuie BP1
  for (int i = 0; i < btn_num - 1 ; i++) {
    if (getBtn(i)) {
      int cf = getCurrentFloor();
      int diff = 0;
      int tg = i + 1;
      if (cf > i) {
        diff = cf - i;
        for (int i = 0; i < diff; i++) {
          display(String("Going up from") + String(cf + 1) + " to " + String(tg), 0, 0);
          stepper(-floor_steps);
          setCurrentFloor(cf + 1);
          display(String("Going up from") + String(getCurrentFloor() + 1) + " to " + String(tg), 0, 0);
        }

      }
      else if (cf < i) {
        diff = i - cf;
        for (int i = 0; i < diff; i++) {
          display(String("Going down from") + String(cf + 1) + " to " + String(tg), 0, 0);
          stepper(floor_steps);
          setCurrentFloor(cf - 1);
          display(String("Going down from") + String(getCurrentFloor() + 1) + " to " + String(tg), 0, 0);
        }

      }

    }
  }
   

}
bool getBtn(int i) {
  bool sg = digitalRead(btn[i]);
  bool r = btn_old_sg[i] != sg && sg == LOW;
  //  if (btn_old_sg[i] != sg && sg == LOW)
  //  {
  //    display(String(i + 1), 0, 0);
  //    Serial.println(i + 1);
  //  }
  btn_old_sg[i] = sg;
  return r;
}
