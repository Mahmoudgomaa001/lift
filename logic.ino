int current_floor = -1;
int target_floor = -1;
void get_init_floor() {
  display(String("Going to init point !"), 0, 0);
  stepper(5000);
  display(String("Start point floor 1 !"), 0, 0);

}
int getCurrentFloor() {
  return current_floor;
}
void setCurrentFloor(int f) {
  current_floor = f;
}
