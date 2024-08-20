#include <iostream>
class myClass {
private:
  int prop2 = 32;

public:
  int prop1;
  int getProp1() { return prop2; }
};
int main() {
  myClass myObj;
  myObj.prop1 = 34;
  std::cout << myObj.getProp1();
  return 0;
}
