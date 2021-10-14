#include <iostream>
using namespace std;
class Base {
public:
  Base() {};
  void public_func() {
    this->private_func();
    this->private_func_const();
  }
  void general_func() { cout << "Base::general_func" << endl; }

private:
  // virtual function的access modifier可以被修改,
  //                   但返回值不可以被修改
  //                   const修饰与不修饰完全就是两个函数
  virtual const int* private_func() {
    cout << "Base::private_func" << endl;
    return new int;
  }
  virtual void private_func_const() const {
    cout << "Base::private_func_const" << endl;
  }
};

class Derived : public Base {
public:
  const int* private_func() override {  // 被重写成功
    cout << "Derived::private_func" << endl;
    return new int;
  }

  // int private_func() { return 10; } // error 返回值不对应

  void private_func_const() {  // 没有被重写成功，const修饰，不对应
    cout << "Derived::private_func_const" << endl;
  }
  void general_func(int x) { cout << "Derived::general_func" << endl; }
  void general_func() { cout << "Derived::general_func" << endl; }

private:
  int val;
};

int main(void) {
  Base* p = new Derived();
  p->public_func();
  // output
  // Derived::private_func
  // Base::private_func_const
  //   p->general_func(2);  // error, Base中看不到general_func(int)的函数
  p->general_func();
  // output
  // Base::general_func
  return 0;
}