#include <iostream>
using namespace std;

class Base {
 public:
  const static int const_static_base = 28;
  static int non_const_static_base;  // 仅仅是一份声明，不能在此处定义 = 2;
};

int Base::non_const_static_base = 29;  // 只能在类外定义和初始化。

int main(void) {
  cout << (new Base())->const_static_base << endl;
  cout << (new Base())->non_const_static_base << endl;
  return 0;
}