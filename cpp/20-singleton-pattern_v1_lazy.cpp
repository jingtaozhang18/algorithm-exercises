#include <iostream>
#include <string>

// 没有利用C++11特性的单实例demo

class Singleton_V1 {
 private:
  std::string content;
  static Singleton_V1* single_;  // 不能在此处初始化 = nullptr;
  static std::mutex mutex_;      // 多线程版本使用的锁
  Singleton_V1(std::string content) {
    this->content = content;
  }                   // 阻止在栈中创建
  ~Singleton_V1() {}  // 阻止在栈中创建

 public:
  Singleton_V1(const Singleton_V1& other) = delete;
  Singleton_V1(const Singleton_V1&& other) = delete;
  // 下面两行，不确定需不需要
  Singleton_V1& operator=(const Singleton_V1& other) = delete;
  Singleton_V1& operator=(Singleton_V1&& other) = delete;
  // 为了解决内存泄漏的问题
  class Deletor {
   public:
    ~Deletor() {
      if (Singleton_V1::single_ != nullptr) {
        delete Singleton_V1::single_;
      }
    }
  };
  static Deletor deletor;  // 在函数退出时自动析构single_指针,充当智能指针的作用
  // 懒汉模式 v1版
  static Singleton_V1* GetInstaceLazy_v1_0(std::string content) {
    if (single_ == nullptr) {
      single_ = new Singleton_V1(content);
    }
    return single_;
  }

  // 懒汉模式，多线程版本，采用双检测锁，避免多次获得锁的资源开销
  // 但仍会有single_指针使用时没有初始化完整的问题（通常因为编译器优化导致的
  static Singleton_V1* GetInstaceLazy_v1_1(std::string content) {
    if (single_ == nullptr) {
      std::lock_guard<std::mutex> lock(mutex_);  // 构造时获得锁，析构时释放锁
      if (single_ == nullptr) {
        single_ = new Singleton_V1(content);
      }
    }
    return single_;
  }
  void calc() { std::cout << content << "\n"; }
};

Singleton_V1* Singleton_V1::single_ = nullptr;  // 在此处初始化
std::mutex Singleton_V1::mutex_;                // 初始化
Singleton_V1::Deletor Singleton_V1::deletor;    // 构造

int main(void) {
  //   Singleton a; // error calling a private constructor of class 'Singleton'
  Singleton_V1::GetInstaceLazy_v1_1("init");
  Singleton_V1* instance = Singleton_V1::GetInstaceLazy_v1_1("single");
  instance->calc();
  return 0;
}