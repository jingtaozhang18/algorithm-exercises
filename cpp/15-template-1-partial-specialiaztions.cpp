#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct myclass {
  void print() { std::cout << "myclass!" << std::endl; }
};

// 类的部分定制, 左值
template <typename T>
struct myclass<T&> {
  void print() { std::cout << "myclass! lvalue" << std::endl; }
};

// 右值
template <typename T>
struct myclass<T&&> {
  void print() { std::cout << "myclass! rvalue" << std::endl; }
};

int main(void) {
  int i(1988);
  int& ri = i;
  myclass<decltype(1988)> mc;  // 原始版本
  mc.print();

  myclass<decltype(ri)> mcl;  // 左值版本
  mcl.print();

  myclass<decltype(std::move(i))> mcr;  // 右值版本
  mcr.print();

  return 0;
}