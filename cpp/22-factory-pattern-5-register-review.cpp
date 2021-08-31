// 参照原版 22-factory-pattern-5-register.cpp文件
#include <iostream>
#include <string>
#include <unordered_map>

#include "22-factory-pattern-0-sport.hpp"

// 抽象的产品类，比如鞋子大类和衣服大类
// 虚类，要结合具体的产品类才能工作
template <class IProductType_t>
class IProductRegistrar {
 public:
  // 纯虚函数，定义了创造的产品的接口
  virtual IProductType_t* CreateProduct() = 0;

 protected:
  IProductRegistrar(){};
  // 析构函数需要是virtual的
  virtual ~IProductRegistrar(){};  // 不能声明称纯虚的

 private:
  // 禁止拷贝构造和赋值构造
  IProductRegistrar(const IProductRegistrar&);
  const IProductRegistrar& operator=(const IProductRegistrar&);
};

// 注册登记类,即真正的工厂
template <class IProductType_t>
class ProductFactory {
 public:
  // 每一个产品大类都会有一个单例
  static ProductFactory<IProductType_t>& Instance() {
    static ProductFactory<IProductType_t> instance;
    return instance;
  }
  // 在一个大类产品中，注册一个具体的商品
  void RegisterProduct(IProductRegistrar<IProductType_t>* p, std::string name) {
    m_ProductRegistry[name] = p;
  }
  // 调用工厂生产产品
  IProductType_t* GetProduct(std::string name) {
    if (m_ProductRegistry.find(name) == m_ProductRegistry.end()) {
      std::cout << "not registered!\n";
      return nullptr;
    } else {
      return m_ProductRegistry[name]->CreateProduct();
    }
  }

 private:
  ProductFactory(){};
  ~ProductFactory(){};
  ProductFactory(const ProductFactory&){};
  const ProductFactory& operator=(const ProductFactory&){};
  std::unordered_map<std::string, IProductRegistrar<IProductType_t>*>
      m_ProductRegistry;
};

// 具体的产品类，继承了产品的大类
template <class IProductType_t, class ProductImpl_t>
class ProductRegistrar : public IProductRegistrar<IProductType_t> {
 public:
  explicit ProductRegistrar(std::string name) {
    ProductFactory<IProductType_t>::Instance().RegisterProduct(this, name);
  }
  // 通过具体的实现类构造大类衣服
  IProductType_t* CreateProduct() { return new ProductImpl_t(); }
};

int main(void) {
  ProductRegistrar<Shoes, NiKeShoes>("Nike");
  Shoes* p = ProductFactory<Shoes>::Instance().GetProduct("Nike");
  if (p != nullptr) {
    p->Show();
    delete p;
  } else {
    std::cout << "product error\n";
  }
  return 0;
}