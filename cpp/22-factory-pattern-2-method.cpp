#include "22-factory-pattern-0-shoes.hpp"
// 总鞋厂
class ShoesFactory {
 public:
  virtual Shoes *CreateShoes() = 0;
  virtual ~ShoesFactory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public ShoesFactory {
 public:
  Shoes *CreateShoes() { return new NiKeShoes(); }
};

// 阿迪达斯生产者/生产链
class AdidasProducer : public ShoesFactory {
 public:
  Shoes *CreateShoes() { return new AdidasShoes(); }
};

// 李宁生产者/生产链
class LiNingProducer : public ShoesFactory {
 public:
  Shoes *CreateShoes() { return new LiNingShoes(); }
};

int main() {
  // ================ 生产耐克流程 ==================== //
  // 鞋厂开设耐克生产线
  ShoesFactory *niKeProducer = new NiKeProducer();
  // 耐克生产线产出球鞋
  Shoes *nikeShoes = niKeProducer->CreateShoes();
  // 耐克球鞋广告喊起
  nikeShoes->Show();
  // 释放资源
  delete nikeShoes;
  delete niKeProducer;

  // ================ 生产阿迪达斯流程 ==================== //
  // 鞋厂开设阿迪达斯生产者
  ShoesFactory *adidasProducer = new AdidasProducer();
  // 阿迪达斯生产线产出球鞋
  Shoes *adidasShoes = adidasProducer->CreateShoes();
  // 阿迪达斯球鞋广喊起
  adidasShoes->Show();
  // 释放资源
  delete adidasShoes;
  delete adidasProducer;

  return 0;
}