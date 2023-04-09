
#define btn_num 5
  int btn [btn_num] = {9, A0, A1, A2, 2};
bool btn_old_sg [btn_num] = {1, 1, 1, 1, 1};
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
  for (int i = 0; i < btn_num ; i++) {
    bool sg = digitalRead(btn[i]);
    if (btn_old_sg[i] != sg && sg == LOW)
    {
      display(String(i+1), 0, 0);
      Serial.println(i+1);
    }
    btn_old_sg[i] = sg;
  }


}
