
#define btn_num 6
int btn [btn_num] = {9, A0, A1, A2, 2, 3};
bool btn_old_sg [btn_num] = {1, 1, 1, 1, 1, 1};


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
  for (int i = 0; i < 4 ; i++) {
    if (getBtn(i)) {
      //      int cf = getCurrentFloor();
      //      int diff = 0;
      //      int tg = i + 1;
      //      if (cf < i) {
      //        diff = i - cf;
      //        for (int i = 0; i < diff; i++) {
      //          display("Current : " + String(getCurrentFloor() + 1), "Target : " + String(tg), get_Up_Arrow_key);
      //          stepper(-getFloorSteps());
      //          setCurrentFloor(getCurrentFloor() + 1);
      //          display("Current : " + String(getCurrentFloor() + 1), "Target : " + String(tg), get_Up_Arrow_key);
      //        }
      //        display("Current : " + String(getCurrentFloor() + 1), "No Orders !", 0);
      //      }
      //      else if (cf > i) {
      //        diff = cf - i;
      //        for (int i = 0; i < diff; i++) {
      //          display("Current : " + String(getCurrentFloor() + 1), "Target : " + String(tg), get_Down_Arrow_key);
      //          stepper(getFloorSteps());
      //          setCurrentFloor(getCurrentFloor() - 1);
      //          display("Current : " + String(getCurrentFloor() + 1), "Target : " + String(tg), get_Down_Arrow_key);
      //        }
      //        display("Current : " + String(getCurrentFloor() + 1), "No Orders !", 0);
      //      }
      changeFloor(i);
    }
  }//for
  

}
bool getBtn(int i) {
  bool sg = digitalRead(btn[i]);
  bool r = btn_old_sg[i] != sg && sg == LOW;
  btn_old_sg[i] = sg;
  return r;
}
int getInitBtnIndex() {
  return 4;
}
int getIRIndex() {
  return 5;
}
