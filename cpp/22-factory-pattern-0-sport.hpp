#include <iostream>
// 基类 衣服
class Clothe {
 public:
  virtual void Show() = 0;
  virtual ~Clothe() {}
};

// 耐克衣服
class NiKeClothe : public Clothe {
 public:
  void Show() { std::cout << "我是耐克衣服，时尚我最在行！" << std::endl; }
};

// 基类 鞋子
class Shoes {
 public:
  virtual void Show() = 0;
  virtual ~Shoes() {}
};

// 耐克鞋子
class NiKeShoes : public Shoes {
 public:
  void Show() { std::cout << "我是耐克球鞋，让你酷起来！" << std::endl; }
};

// 优衣库衣服
class UniqloClothe : public Clothe {
 public:
  void Show() {
    std::cout << "我是优衣库衣服，我的广告语：I am Uniqlo" << std::endl;
  }
};