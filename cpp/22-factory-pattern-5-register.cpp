#include <map>

#include "22-factory-pattern-0-sport.hpp"
// 基类，产品注册模板接口类
// 模板参数 ProductType_t 表示的类是产品抽象类
template <class ProductType_t>
class IProductRegistrar {
public:
  // 获取产品对象抽象接口
  virtual ProductType_t* CreateProduct() = 0;

protected:
  // 禁止外部构造和虚构, 子类的"内部"的其他函数可以调用
  IProductRegistrar() {}
  virtual ~IProductRegistrar() {}

private:
  // 禁止外部拷贝和赋值操作
  IProductRegistrar(const IProductRegistrar&);
  const IProductRegistrar& operator=(const IProductRegistrar&);
};

// 工厂模板类，用于获取和注册产品对象
// 模板参数 ProductType_t 表示的类是产品抽象类
template <class ProductType_t>
class ProductFactory {
public:
  // 获取工厂单例，工厂的实例是唯一的
  static ProductFactory<ProductType_t>& Instance() {
    // 针对每种商品一个单例
    static ProductFactory<ProductType_t> instance;
    return instance;
  }

  // 产品注册
  void RegisterProduct(IProductRegistrar<ProductType_t>* registrar,
    std::string name) {
    m_ProductRegistry[name] = registrar;
  }

  // 根据名字name，获取对应具体的产品对象
  ProductType_t* GetProduct(std::string name) {
    // 从map找到已经注册过的产品，并返回产品对象
    if (m_ProductRegistry.find(name) != m_ProductRegistry.end()) {
      return m_ProductRegistry[name]->CreateProduct();
    }

    // 未注册的产品，则报错未找到
    std::cout << "No product found for " << name << std::endl;

    return NULL;
  }

private:
  // 禁止外部构造和虚构
  ProductFactory() {
    std::cout << "ProductFactory has been created!" << std::endl;
  }
  ~ProductFactory() {}

  // 禁止外部拷贝和赋值操作
  ProductFactory(const ProductFactory&);
  const ProductFactory& operator=(const ProductFactory&);

  // 保存注册过的产品，key:产品名字 , value:产品类型
  std::map<std::string, IProductRegistrar<ProductType_t>*> m_ProductRegistry;
};

// 产品注册模板类，用于创建具体产品和从工厂里注册产品
// 模板参数 ProductType_t 表示的类是产品抽象类（基类），ProductImpl_t
// 表示的类是具体产品（产品种类的子类）
template <class ProductType_t, class ProductImpl_t>
class ProductRegistrar : public IProductRegistrar<ProductType_t> {
public:
  // 构造函数，用于注册产品到工厂，只能显示调用
  explicit ProductRegistrar(std::string name) {
    // 通过工厂单例把产品注册到工厂
    ProductFactory<ProductType_t>::Instance().RegisterProduct(this, name);
  }

  // 创建具体产品对象指针
  ProductType_t* CreateProduct() { return new ProductImpl_t(); }
};

int main() {
  // ========================== 生产耐克球鞋过程 ===========================//
  // 注册产品种类为Shoes（基类），产品为NiKe（子类）到工厂，产品名为nike
  ProductRegistrar<Shoes, NiKeShoes> nikeShoes("nike");
  // 从工厂获取产品种类为Shoes，名称为nike的产品对象
  Shoes* pNiKeShoes = ProductFactory<Shoes>::Instance().GetProduct("nike");
  // 显示产品的广告语
  pNiKeShoes->Show();
  // 释放资源
  if (pNiKeShoes) {
    delete pNiKeShoes;
  }

  // ========================== 生产优衣库衣服过程 ===========================//
  // 注册产品种类为Clothe（基类），产品为UniqloClothe（子类）到工厂，产品名为uniqlo
  ProductRegistrar<Clothe, UniqloClothe> adidasShoes("uniqlo");
  // 从工厂获取产品种类为Shoes，名称为adidas的产品对象
  Clothe* pUniqloClothe =
    ProductFactory<Clothe>::Instance().GetProduct("uniqlo");
  // 显示产品的广告语
  pUniqloClothe->Show();
  // 释放资源
  if (pUniqloClothe) {
    delete pUniqloClothe;
  }

  return 0;
}