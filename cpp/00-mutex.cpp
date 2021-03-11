// 编译 & 执行命令
// g++ -pthread -o main 00-mutex.cpp  && ./main
#include<mutex>
#include<thread>
#include<iostream>
using namespace std;

mutex mtx;


void print_block (int n, char c) {
  this_thread::sleep_for(std::chrono::seconds(1));
  mtx.lock();
    // 互斥区
    for (int i=0; i<n; ++i) { cout << c; }
    cout << '\n';
  mtx.unlock();
}

int main(void){
  mutex lock;
  // mutex l2 = lock; // 禁止赋值
  // mutex l3 = move(lock); // 禁止移动

  thread th1 (print_block, 50, '*'); // 创建并执行线程
  thread th2 (print_block, 50, '$');

  th1.join();
  th2.join();

  return 0;
}