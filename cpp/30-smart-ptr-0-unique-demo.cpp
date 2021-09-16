#include <functional>
#include <iostream>
#include <memory>
using namespace std;

// from ms intern project
class Snr {
 private:
  string name;
  Snr(string name) : name(name) { cout << "Snr private construct" << endl; };
  ~Snr() { cout << "Snr private destruct" << endl; };

 public:
  static const Snr* Create(string name) { return new Snr(name); }
  static void Destroy(Snr* snr) { delete snr; }
  void say() const { cout << "My name is " << name << ". I am alive." << endl; }
};

struct SnrDeleter {
  void operator()(const Snr* p) {
    if (p) {
      Snr* non_const_ptr = const_cast<Snr*>(p);
      cout << "const ptr is:\t\t " << p << endl;
      cout << "non const ptr is:\t " << non_const_ptr << endl;
      Snr::Destroy(non_const_ptr);
    }
    p = nullptr;
  }
};

unique_ptr<const Snr, SnrDeleter> uptr;
int main(void) {
  uptr.reset(Snr::Create("v1"));
  uptr.get()->say();
  // uptr.reset(nullptr);
  cout << "exit" << endl;
  return 0;
}