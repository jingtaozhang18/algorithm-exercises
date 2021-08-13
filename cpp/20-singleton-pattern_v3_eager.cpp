#include <iostream>
#include <string>

// 利用了c++11特性的
// 编译器保证了内部静态变量的线程安全性
class Singleton_V3 {
 private:
  std::string content;
  static Singleton_V3 single_;
  // 因为声明了下面的构造函数，不能使用不带参数的构造函数了
  Singleton_V3(std::string content) {
    this->content = content;
  }                   // 阻止在栈中创建
  ~Singleton_V3() {}  // 阻止在栈中创建

 public:
  Singleton_V3(const Singleton_V3& other) = delete;
  Singleton_V3(const Singleton_V3&& other) = delete;
  // 下面两行，不确定需不需要
  Singleton_V3& operator=(const Singleton_V3& other) = delete;
  Singleton_V3& operator=(Singleton_V3&& other) = delete;
  // 懒汉模式 v1版
  static Singleton_V3* GetInstaceLazy_v3() { return &single_; }
  void calc() { std::cout << content << "\n"; }
};

Singleton_V3 Singleton_V3::single_("init");

int main(void) {
  //   Singleton a; // calling a private constructor of class 'Singleton'
  Singleton_V3::GetInstaceLazy_v3();
  Singleton_V3* instance = Singleton_V3::GetInstaceLazy_v3();
  instance->calc();
  return 0;
}