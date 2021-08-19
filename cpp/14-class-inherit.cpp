class Base {
 public:
  virtual void func_1() const {};
  virtual void func_2() const {};
  virtual void func_3() const final{};
};

class Dervied : public Base {
 public:
  // 可以通过编译，但是下面的func_1不是一个重写函数
  virtual void func_1() {}

  // 通过override显式声明可以避免出现func_1的错误情况
  //   virtual void func_2() override {} // error

  // Base中通过final的指定，禁止了此处的继续重写
  //   virtual void func_3() const override {}; // error
};