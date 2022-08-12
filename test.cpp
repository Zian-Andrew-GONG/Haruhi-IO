#include <iostream>

class T1 {
  public:
    std::string type() { return "T1"; }
    void print1() { std::cout << "T1" << std::endl; }
};
class T2 {
  public:
    std::string type() { return "T2"; }
    void print2() { std::cout << "T2" << std::endl; }
};

template<typename T>
void print(T t) {
  if(t.type() == "T1") {
    t.print1();
  }
  if(t.type() == "T2") {
    t.print2();
  }
}
int main() {
  T1 t1;
  print(t1);
}