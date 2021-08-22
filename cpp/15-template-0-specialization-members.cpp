#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct myclass {
  void print() { std::cout << "myclass!" << std::endl; }
};

//定制成员的int版本
template <>
void myclass<int>::print() {
  std::cout << "myclass! int" << std::endl;
}

int main(void) {
  myclass<double> mcd;
  mcd.print();

  myclass<int> mci;
  mci.print();

  return 0;
}