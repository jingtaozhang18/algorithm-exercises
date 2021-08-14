#include <algorithm>
#include <iostream>
#include <string>

class Human {
 public:
  // default constructor
  Human() {
    log("default constructor");
    age = 0;
    name = nullptr;
  }

  // deconstructor
  ~Human() {
    log("destructor");
    if (this->name != nullptr) {
      delete this->name;
    }
  }

  // constructor with parameter
  explicit Human(int age)  // 禁止隐式转换
      : age(age),
        name(nullptr)  // 成员初始化列表进行初始化
  {
    log("constructor with parameter");
  }

  // constructor with parameter
  Human(char *name, int age)
      : age(age)  // 初始化列表进行初始化
  {
    log("constructor with parameter");
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
  }

  // copy constructor
  Human(const Human &other) {
    log("copy constructor");
    // 保证在申请资源失败的时候不会影响到原来的资源
    Human tmp(other.name, other.age);
    // 和临时变量交换资源，临时变量的资源会在方法退出后被释放掉
    std::swap(this->age, tmp.age);
    std::swap(this->name, tmp.name);
  }

  // move copy Constructor
  Human(Human &&other) {
    // this 是一片没有被初始化的空间
    log("move copy Constructor");
    this->age = other.age;
    this->name = other.name;
    other.name = nullptr;  // 此处的构造函数没有为this->name的内容进行初始化
  }

  // copy assignment operator
  Human &operator=(const Human &other) {
    log("copy assignment operator");
    if (this == &other) {
      return *this;
    }
    // 保证在申请资源失败的时候不会影响到原来的资源
    Human tmp(other.name, other.age);
    // 和临时变量交换资源，临时变量的资源会在方法退出后被释放掉
    std::swap(this->age, tmp.age);
    std::swap(this->name, tmp.name);
    return *this;
  }

  // move assignment operator
  Human &operator=(Human &&other) {  // 要修改other，不能使用const修饰
    log("move assignment operator");
    std::swap(age, other.age);
    std::swap(name, other.name);
    return *this;
  }

  // 友元函数，可以访问类的私有变量
  friend Human borth(Human &mother, Human &father);

  void show() {
    std::cout << "a human instance: \n"
              << "\tname: " << this->name << "\n"
              << "\tage: " << this->age << "\n";
  }

 private:
  void log(const char *msg) { std::cout << "[" << this << "] " << msg << "\n"; }
  int age;
  char *name;
};

Human borth(Human &mother, Human &father) {
  Human baby(0);
  int i, m = mother.name ? strlen(mother.name) : 0,
         n = father.name ? strlen(father.name) : 0;
  baby.name = new char[m + n + 2];
  for (i = 0; i < m; ++i) baby.name[i] = mother.name[i];
  baby.name[i++] = ' ';
  for (; i < m + n + 1; ++i) baby.name[i] = father.name[i - m - 1];
  baby.name[i] = 0;
  return baby;
}

int main(void) {
  Human c1("c1", 18);  // "c1" 的用法并不规范
  // output
  // [0x16fdff2d8] constructor with parameter
  Human c2(c1);
  // output
  // [0x16fdff2c8] copy constructor
  // [0x16fdff180] constructor with parameter
  // [0x16fdff180] destructor
  Human c4;
  // output
  // [0x16fdff2a8] default constructor
  c4 = c2;
  // [0x16fdff2a8] copy assignment operator
  // [0x16fdff1a8] constructor with parameter
  // [0x16fdff1a8] destructor
  std::cout << "------------------------\n";
  Human c5;
  // output
  // [0x16fdff298] default constructor
  Human mother("mom", 26);
  // output
  // [0x16fdff288] constructor with parameter
  Human father("dad", 27);
  // output
  // [0x16fdff278] constructor with parameter
  c5 = borth(mother, father);
  // output
  // [0x16fdff268] constructor with parameter
  // [0x16fdff298] move assignment operator
  // [0x16fdff268] destructor
  Human c6 = std::move(c5);  // 移动复制构造函数
  // output
  // [0x16fdff258] move copy Constructor
  std::cout << "------------------------\n";
  Human c7;
  // output
  // [0x16fdff248] default constructor
  c7 = Human();
  // output
  // [0x16fdff238] default constructor
  // [0x16fdff248] move assignment operator
  // [0x16fdff238] destructor
  Human c7_o;
  // output
  // [0x16fdff228] default constructor
  c7_o = Human();
  // output
  // [0x16fdff218] default constructor
  // [0x16fdff228] move assignment operator
  // [0x16fdff218] destructor
  Human c8 = borth(c7, c7_o);
  // output
  // [0x16fdff208] constructor with parameter
  std::cout << "<<<<<<finish >>>>>>>>\n";
  // output
  // [0x16fdff208] destructor  c8
  // [0x16fdff228] destructor  c7_o
  // [0x16fdff248] destructor  c7
  // [0x16fdff258] destructor  c6
  // [0x16fdff278] destructor  father
  // [0x16fdff288] destructor  mother
  // [0x16fdff298] destructor  c5
  // [0x16fdff2a8] destructor  c4
  // [0x16fdff2c8] destructor  c2
  // [0x16fdff2d8] destructor  c1
  return 0;
}