#include"02-semaphore.hpp"
#include<iostream>
#include<mutex>
#include<string>
using namespace std;

class ReaderWriterRPriority{ // 读者优先的读者写者模型
  private:
    mutex mtx; // 控制读者数量变量的访问
    int count=0; // 读者数量
    semaphore rw; // 读写互斥锁 读-读共享，读-写、写-写互斥
    string mem="hello";
  public:
    ReaderWriterRPriority():rw(1){};
    void read(){
      mtx.lock();
        if(count++==0) rw.wait(); // 读写互斥锁
      mtx.unlock();

      cout<<mem<<endl;

      mtx.lock();
        if(--count==0) rw.signal();
      mtx.unlock();
    }
    void write(const string &s){
      rw.wait();
        mem = s;
      rw.signal();
    }
};


class ReaderWriterWPriority{ // 写者优先的读者写者模型
  private:
    mutex mtx, mtxWriter; // 控制读者数量变量的访问
    semaphore flag; // 控制读者不能排队
    semaphore rw, w; // 读写锁， 写锁
    int count=0, countWriger=0; // 读者数量
    string mem="hello";
  public:
    ReaderWriterWPriority():rw(1), w(1), flag(1){};
    void read(){
      flag.wait(); // 读队列上禁止排队， 为了让写进程有机会拿到s_write锁  读者一个一个的来，减少了获取到w锁的概率
        w.wait(); // 用于被写进程阻塞
          mtx.lock();
            if(count++==0) rw.wait(); // 占用内容的互斥
          mtx.unlock();
        w.signal();
      flag.signal();

      cout<<mem<<endl;

      mtx.lock(); // 释放资源
        if(--count==0) rw.signal();
      mtx.unlock();
    }
    void write(const string &s){
      mtxWriter.lock();
        if(countWriger++==0) w.wait(); // 写者优先锁 拿到之后会阻塞之后的读进程
      mtxWriter.unlock();
      // 修改内容
      rw.wait();
        mem = s;
      rw.signal();
      // 尝试释放写占领锁
      mtxWriter.lock();
        if(--countWriger==0) w.signal(); // 写者优先锁 拿到之后会阻塞之后的读进程
      mtxWriter.unlock();
    }
};


class ReaderWriterFair{ // 公平的读者写者模型
  private:
    mutex mtx; // 控制读者数量变量的访问
    semaphore flag; // 控制读者-写者之间的公平竞争 类似与串行化了
    semaphore rw; // 读写锁
    int count=0; // 读者数量
    string mem="hello";
  public:
    ReaderWriterFair():rw(1), flag(1){};
    void read(){
      flag.wait();
        mtx.lock();
          if(count++==0) rw.wait(); // 占用内容的互斥
        mtx.unlock();
      flag.signal();

      cout<<mem<<endl;

      mtx.lock();
        if(--count==0) rw.signal();
      mtx.unlock();
    }
    void write(const string &s){
      flag.wait();
        rw.wait();
          mem = s;
        rw.signal();
      flag.signal();
    }
};
