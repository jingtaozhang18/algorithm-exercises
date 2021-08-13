#include "22-factory-pattern-0-shoes.hpp"
enum SHOES_TYPE { NIKE, LINING, ADIDAS };
// 总鞋厂
class ShoesFactory {
 public:
  // 根据鞋子类型创建对应的鞋子对象
  Shoes *CreateShoes(SHOES_TYPE type) {
    switch (type) {
      case NIKE:
        return new NiKeShoes();
        break;
      case LINING:
        return new LiNingShoes();
        break;
      case ADIDAS:
        return new AdidasShoes();
        break;
      default:
        return NULL;
        break;
    }
  }
};

int main() {
  // 构造工厂对象
  ShoesFactory shoesFactory;

  // 从鞋工厂对象创建阿迪达斯鞋对象
  Shoes *pNikeShoes = shoesFactory.CreateShoes(NIKE);
  if (pNikeShoes != NULL) {
    // 耐克球鞋广告喊起
    pNikeShoes->Show();

    // 释放资源
    delete pNikeShoes;
    pNikeShoes = NULL;
  }

  // 从鞋工厂对象创建阿迪达斯鞋对象
  Shoes *pLiNingShoes = shoesFactory.CreateShoes(LINING);
  if (pLiNingShoes != NULL) {
    // 李宁球鞋广告喊起
    pLiNingShoes->Show();

    // 释放资源
    delete pLiNingShoes;
    pLiNingShoes = NULL;
  }

  // 从鞋工厂对象创建阿迪达斯鞋对象
  Shoes *pAdidasShoes = shoesFactory.CreateShoes(ADIDAS);
  if (pAdidasShoes != NULL) {
    // 阿迪达斯球鞋广告喊起
    pAdidasShoes->Show();

    // 释放资源
    delete pAdidasShoes;
    pAdidasShoes = NULL;
  }

  return 0;
}
