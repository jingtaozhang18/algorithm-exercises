// https://leetcode-cn.com/problems/print-zero-even-odd/
#include<bits/stdc++.h>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int cur;
    mutex lz, lj, lo;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        cur=1;
        lj.lock();
        lo.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(cur<=n){
            printNumber(0);
            if(cur%2){
                lj.unlock();
            }else{
                lo.unlock();
            }
            if(cur==1) lz.lock();
            lz.lock();
            ++cur;
        }
        // 通知结束
        lj.unlock();
        lo.unlock();
    }

    void even(function<void(int)> printNumber) {
        while(true){
            lo.lock();
            if(cur<=n) {
                printNumber(cur);
                lz.unlock();
            }
            else break;
        }
    }

    void odd(function<void(int)> printNumber) {
        while(true){
            lj.lock();
            if(cur<=n) {
                printNumber(cur);
                lz.unlock();
            }
            else break;
        }
    }
};