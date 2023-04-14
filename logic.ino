int current_floor = -1;
int target_floor = -1;
#define floor_steps  1920
#define current_str  "Current : "
#define target_str  "Target  : "
#define no_order_str  "No orders !"

int load = 0;
#define max_load  2
bool load_mode = 1;

unsigned long  timer = 0;
#define timer_time_out  10000
bool  access = 0;
String coming_card = "";
#define Authorized_size 2
String Authorized_cards[] = {"D3C4A71A", "D6172F1E"};
String Authorized_names[] = {"BienvenueOuiam ", "BienvenueRaounak"};
void get_init_floor() {
  display("", target_str + String("0"), getDownArrowkey());
  stepper(5000);
  current_floor = 0;
  display("Welcome !!!", no_order_str, getNoArrowkey());
}
int getCurrentFloor() {
  return current_floor;
}
void setCurrentFloor(int f) {
  current_floor = f;
}
int getFloorSteps() {
  return floor_steps;
}
void changeFloor(int i) {

  //  if (!access)return;
  if (load > max_load) {
    target_floor = i;
    load_mode = 0;
    return;
  }

  int diff = 0;
  target_floor = i ;
  if (current_floor == i)return;
  else if (current_floor < i) {
    if (getDoorStatus())closeDoor();

    diff = i - current_floor;
    for (int i = 0; i < diff; i++) {
      display(current_str + String(current_floor), target_str + String(target_floor), getUpArrowkey());
      stepper(-getFloorSteps());
      current_floor = current_floor + 1;
      display(current_str + String(current_floor), target_str + String(target_floor), getUpArrowkey());
    }
    display(current_str + String(current_floor ), no_order_str, getNoArrowkey());

  }
  else if (current_floor > i) {
    if (getDoorStatus())closeDoor();
    diff = current_floor - i;
    for (int i = 0; i < diff; i++) {
      display(current_str + String(current_floor), target_str + String(target_floor), getDownArrowkey());
      stepper(getFloorSteps());
      current_floor = current_floor - 1;
      display(current_str + String(current_floor ), target_str + String(target_floor), getDownArrowkey());
    }
    display(current_str + String(current_floor ), no_order_str, getNoArrowkey());

  }
  if (access) {
    openDoor();
    delay(5000);
    closeDoor();
  }
  load_mode = 1;
  load = 0;
  access = 0;
  display(current_str + String(current_floor ), no_order_str, getNoArrowkey());
}

void handler() {

  if (coming_card != "") {
    dingC();
    for (int i = 0; i < Authorized_size; i++) {
      if (coming_card == Authorized_cards[i]) {
        display(Authorized_names[i], "Opening door", getNoArrowkey());
        access = 1;
        coming_card = "";
      }
    }
    if (coming_card != "") {
      display("Anonymous user", "Access denied", getNoArrowkey());
      coming_card = "";
      timer = millis();
    }

  }
  if (timer == 0 && access) {

    openDoor();
    display("MaxLoad:" + String(max_load) + " L:" + String(load), "Waiting !!!", getNoArrowkey());
    timer = millis();
  }
  if (access &&  millis() < timer + timer_time_out) {

    if (getBtn(getIRIndex())) {
      if (load_mode) {
        load++;
        display("MaxLoad:" + String(max_load) + " L:" + String(load), "Waiting !!!", getNoArrowkey());
        //print
      }
      else if (!load_mode && load > 0) {
        load--;
        display("MaxLoad:" + String(max_load) + " L:" + String(load), "", getNoArrowkey());
        if (load == max_load) {
          changeFloor(target_floor);
        }
      }  //print
      if (load > max_load) {
        display("MaxLoad:" + String(max_load) + " L:" + String(load), "Overload !!!", getNoArrowkey());
        timer = millis();
      }
    }


  }

  if (access &&  millis() > timer + timer_time_out) {
    access = 0;
    timer = 0;
    if (getDoorStatus())closeDoor();
    display("Welcome !!!", no_order_str, getNoArrowkey());
  }
  if (!access &&  millis() > timer + timer_time_out && timer != 0) {

    display("Welcome !!!", no_order_str, getNoArrowkey());
    timer = 0;
  }

}
bool getAccess() {
  return access;
}
void setAccess(bool b) {
  access = b;
}
void setCard(String x) {
  coming_card = x;
}
