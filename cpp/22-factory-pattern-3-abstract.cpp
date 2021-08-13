#include "22-factory-pattern-0-sport.hpp"
// 总厂
class Factory {
 public:
  virtual Shoes *CreateShoes() = 0;
  virtual Clothe *CreateClothe() = 0;
  virtual ~Factory() {}
};

// 耐克生产者/生产链
class NiKeProducer : public Factory {
 public:
  Shoes *CreateShoes() { return new NiKeShoes(); }

  Clothe *CreateClothe() { return new NiKeClothe(); }
};

int main() {
  // ================ 生产耐克流程 ==================== //
  // 鞋厂开设耐克生产线
  Factory *niKeProducer = new NiKeProducer();

  // 耐克生产线产出球鞋
  Shoes *nikeShoes = niKeProducer->CreateShoes();
  // 耐克生产线产出衣服
  Clothe *nikeClothe = niKeProducer->CreateClothe();

  // 耐克球鞋广告喊起
  nikeShoes->Show();
  // 耐克衣服广告喊起
  nikeClothe->Show();

  // 释放资源
  delete nikeShoes;
  delete nikeClothe;
  delete niKeProducer;

  return 0;
}