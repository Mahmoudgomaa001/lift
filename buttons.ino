
#define btn_num 7
int btn [btn_num] = {1, A0, A1, A2, 2, 3, A3};
bool btn_old_sg [btn_num] = {1, 1, 1, 1, 1, 1, 1};


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
      changeFloor(i);
    }
  }//for
  if (getBtn(6)) {
    dingO();
  }

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
