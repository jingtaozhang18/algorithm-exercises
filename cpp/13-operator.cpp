#include <iostream>
using namespace std;

class Int {
 public:
  Int(){};
  Int(int val) : val(val) { cout << "Int(int val)" << endl; }
  Int(Int& other) : val(other.val) { cout << "Int(Int& other)" << endl; }
  Int(Int&& other) : val(other.val) { cout << "Int(Int&& other)" << endl; }
  Int& operator=(const Int& other) {
    cout << "Int& operator=(const Int& other)" << endl;
    this->val = other.val;
    return *this;
  }
  Int& operator=(const Int&& other) {
    cout << "Int& operator=(const Int&& other)" << endl;
    this->val = other.val;
    return *this;
  }
  // ++Int
  Int& operator++() {
    // this 是一个指针
    cout << "operator++()" << endl;
    this->val += 1;
    return *this;
  }

  // Int++的实现
  Int operator++(int) {
    cout << "operator++(int)" << endl;
    Int result = *this;
    ++(*this);
    return result;
  }

  // 通过友函数 重载<<操作符
  friend ostream& operator<<(ostream& os, const Int& x);

 private:
  int val;
};

// 下面的函数不能添加范围限制符
ostream& operator<<(ostream& os, const Int& x) {
  os << x.val;
  return os;
};

int main(void) {
  Int x(10);
  // output
  // Int(int val)
  Int y;
  cout << "############" << endl;
  y = x++;
  cout << "############" << endl;
  // output
  // operator++(int)
  // Int(Int& other)
  // operator++()
  // Int& operator=
  cout << y << endl;
  // output
  // 10
  cout << x << endl;
  // output
  // 11
  Int z = y++;
  cout << endl;
  // operator++(int)
  // Int(Int& other)
  // operator++()
  return 0;
}
