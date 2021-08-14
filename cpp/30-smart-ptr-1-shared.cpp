#include <iostream>
#include <memory>
using namespace std;

class Basic {
 public:
  Basic() { cout << "Basic" << endl; }
  ~Basic() { cout << "~Basic" << endl; }
};

int main(void) {
  int *p = new int[10];
  shared_ptr<int> ptr(p, [](int *p) {
    delete[] p;
    cout << "Delete memory at " << p << endl;
  });
  Basic *p1 = new Basic[3];
  shared_ptr<Basic> ptr1(p1, [](Basic *p) { delete[] p; });  // 自定义删除行为
  // 或者
  Basic *p2 = new Basic[3];
  shared_ptr<Basic[]> ptr2(p2);
  return 0;
}
