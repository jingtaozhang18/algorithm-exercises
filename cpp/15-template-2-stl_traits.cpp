#include <iostream>

/*
 version 1
 只能进行参数推导，不能进行返回值推导
 */
template <class I, class T>
void func_impl(I iter, T t) {
  T tmp = *iter;
}

template <class I>
inline void func_0(I iter) {
  func_impl(iter, *iter);
}

/*
 version 2
 在迭代器中指定类型, 可以指定返回值的类型，但是无法处理原生指针的情况
 */
template <class T>
struct MyIter {
  typedef T value_type;
  T* ptr;
  MyIter(T* p = 0) : ptr(p) {}
  T& operator*() const { return *ptr; }
};

// 在返回值中可以声明类型，但不能萃取原生指针
template <class I>
typename I::value_type func_1(I ite) {
  return *ite;
}

/*
 version 3
 在version2的基础之上，添加partial specialization
*/
template <class I>
struct iterator_traits {
  typedef typename I::value_type value_type;
};

// 偏特化，指针类型的会使用这个版本
template <class I>
struct iterator_traits<I*> {
  typedef I value_type;
};

// 在返回值中可以声明类型
template <class I>
typename iterator_traits<I>::value_type func_2(I ite) {
  return *ite;
}

int main() {
  int* a = new int(2);
  MyIter<int> b(a);

  //   std::cout << func_1(a) << std::endl; // error 无法萃取
  std::cout << func_1(b) << std::endl;  // 可以萃取
  // 偏特化之后，两种指针都可以了
  std::cout << func_2(a) << std::endl;
  std::cout << func_2(b) << std::endl;
}