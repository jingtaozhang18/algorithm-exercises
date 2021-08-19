#include <iostream>
#include <memory>
using namespace std;
class Parent;
class Child;
class Parent {
 public:
  // 换成weak_ptr<Child> childptr; 之后会出现析构才能正常
  //   shared_ptr<Child> childptr;
  weak_ptr<Child> childptr;
  Parent() { cout << "Parent" << endl; }
  ~Parent() { cout << "~Parent" << endl; }
};
class Child {
 public:
  // 换成weak_ptr<Child> childptr; 之后会出现析构才能正常
  //   shared_ptr<Parent> parentptr;
  weak_ptr<Parent> parentptr;
  Child() { cout << "Child" << endl; }
  ~Child() { cout << "~Child" << endl; }
};
int main() {
  shared_ptr<Parent> parent(new Parent());
  shared_ptr<Child> child(new Child());
//   parent->childptr = child;
//   child->parentptr = parent;
}

// 没有产生析构的输出；
// 两处其实只需要一处修改成weak_ptr，打破环路即可
//     parent                   child
//       |                        |
//       V                        V
//  +---Parent---+           +---Child---+
//  |  childptr  |---------->|           |
//  |            |<----------| parentptr |
//  +------------+           +-----------+
// 在堆上的指针不要是shared_ptr，因为存在于堆上，没有显示的delete操作会造成相互引用，谁都不能计数为0