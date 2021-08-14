#include <functional>
#include <iostream>
#include <memory>
using namespace std;

class Base {
 public:
  Base() { cout << "Base" << endl; }
  ~Base() { cout << "~Base" << endl; }
};
struct MyDeleter {
  void operator()(Base *p) {
    cout << "Delete memory[] at " << p << endl;
    delete[] p;
  }
};
int main() {
  Base *p = new Base();  // Base
  cout << p << endl;     // 0x7fd81fc059f0
  unique_ptr<Base> ptr(p);
  // unique_ptr<Base> ptr2 = ptr;   // not
  // allowed，这也决定了unique_ptr不能通过值传递，只能通过引用传递或者move传递
  unique_ptr<Base> ptr2;
  ptr2 = std::move(ptr);  // ptr2原来指向的内容会被删除，
                          // ptr放弃了控制权，把其管理的内容交给了ptr2来管理
  cout << ptr.get() << endl;                        // 0x0
  cout << ptr2.get() << endl;                       // 0x7fd81fc059f0
  unique_ptr<Base[], MyDeleter> ptr3(new Base[3]);  // 使用自定的deleter函数
  // // 因为使用了自定义的deleter，这种表述也是ok的
  unique_ptr<Base, MyDeleter> ptr4(new Base[3]);
  unique_ptr<Base[], void (*)(Base * p)> ptr5(
      new Base[3], [](Base *p) {  // 使用普通的函数
        cout << "Delete memory[] at " << p << endl;
        delete[] p;
      });
  unique_ptr<Base[], std::function<void(Base *)>> ptr6(
      new Base[3], [](Base *p) { delete[] p; });  // 也是ok的
  return 0;
}

// ~Base
// void (*)(Base * p)
// 是一种数据类型，该类型是一个指针，指向一个void返回值，Base*的参数的函数 void
// *(Base * p) 则是在声明一个函数

void func5(unique_ptr<Base> ptr) {
  cout << "ptr in function: " << ptr.get() << endl;
}

int main_() {
  Base *p = new Base();
  cout << "p = " << p << endl;
  unique_ptr<Base> ptr(p);
  func5(move(
      ptr));  // 转换成右值,在函数传值的时候,ptr放弃了控制权,在函数退出时,对象随着指针的析构而释放
  cout << "ptr in main: " << ptr.get() << endl;
  return 0;
}
