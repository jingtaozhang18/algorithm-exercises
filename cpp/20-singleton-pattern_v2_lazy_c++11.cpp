#include <iostream>
#include <string>

// 利用了c++11特性的
// 编译器保证了内部静态变量的线程安全性
class Singleton_V2 {
 private:
  std::string content;
  Singleton_V2(std::string content) {
    this->content = content;
  }                   // 阻止在栈中创建
  ~Singleton_V2() {}  // 阻止在栈中创建

 public:
  Singleton_V2(const Singleton_V2& other) = delete;
  Singleton_V2(const Singleton_V2&& other) = delete;
  // 下面两行，不确定需不需要
  Singleton_V2& operator=(const Singleton_V2& other) = delete;
  Singleton_V2& operator=(Singleton_V2&& other) = delete;
  // 懒汉模式 v1版
  static Singleton_V2* GetInstaceLazy_v2(std::string content) {
    static Singleton_V2 single_(content);  // local static
    return &single_;
  }
  void calc() { std::cout << content << "\n"; }
};

int main(void) {
  //   Singleton a; // calling a private constructor of class 'Singleton'
  Singleton_V2::GetInstaceLazy_v2("init");
  Singleton_V2* instance = Singleton_V2::GetInstaceLazy_v2("single");
  instance->calc();
  return 0;
}