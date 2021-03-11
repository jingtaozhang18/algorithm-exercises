// g++ -pthread -o main 02-semaphore.cpp  && ./main
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

#ifndef _jingtao_semaphore
class semaphore{
	private:		
		int count;
		mutex mtk;
		condition_variable cv;
	public:
		semaphore(int val=1):count(val){}
		void wait(){
			unique_lock<mutex> lck(mtk);
			if(--count<0) cv.wait(lck);
		}
		void signal(){
			unique_lock<mutex> lck(mtk);
			if(++count<=0) cv.notify_one();
		}
};
#endif

// 测试环境
semaphore plate(1), apple(0), orange(0);
void father(){
    while (true){
        plate.wait();
        cout << "往盘中放一个苹果" << endl;
        apple.signal();
    }
}

void mother(){
    while (true){
        plate.wait();
        cout << "往盘中放一个橘子" << endl;
        orange.signal();
    }
}

void son(){
    while (true){
        apple.wait();
        cout << "儿子吃苹果" << endl;
        plate.signal();
    }
}

void daughter(){
    while (true){
        orange.wait();
        cout << "女儿吃橘子" << endl;
        plate.signal();
    }
}

int main(){
    thread f(father), m(mother), s(son), d(daughter);
    f.join();
    m.join();
    s.join();
    d.join();
}