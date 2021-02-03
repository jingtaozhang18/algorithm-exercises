// https://leetcode-cn.com/problems/fizz-buzz-multithreaded/
#include<bits/stdc++.h>
using namespace std;

class FizzBuzz {
private:
    int n;
    int cur;
    mutex lf, lb, lfb, ln;

public:
    FizzBuzz(int n) {
        this->n = n;
        cur = 1;
        lf.lock();
        lb.lock();
        lfb.lock();
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(cur <= n){
            lf.lock();
            if(cur > n) break;
            printFizz();
            ln.unlock();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(cur <= n){
            lb.lock();
            if(cur > n) break;
            printBuzz();
            ln.unlock();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(cur <= n){
            lfb.lock();
            if(cur > n) break;
            printFizzBuzz();
            ln.unlock();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(cur <= n){
            if(cur % 3 == 0 && cur % 5 == 0){
                lfb.unlock();
            }else if(cur % 3 == 0){
                lf.unlock();
            }else if(cur % 5 == 0){
                lb.unlock();
            }else{
                printNumber(cur);
                ln.unlock();
            }
            ln.lock(); // 等待信号量
            ++cur;
        }
        // 以下三个post通过更新sem_fizz等信号量，调动其他线程运行，进而结束所有线程
        lf.unlock();
        lb.unlock();
        lfb.unlock();
    }
};