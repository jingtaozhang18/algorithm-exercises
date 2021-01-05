// https://leetcode-cn.com/problems/print-foobar-alternately/
#include<bits/stdc++.h>
using namespace std;

class FooBar {
private:
    int n;

public:
    mutex mtx1, mtx2;
    FooBar(int n) {
        this->n = n;
        mtx2.lock();
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
          mtx1.lock();
        	printFoo();
          mtx2.unlock();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
          mtx2.lock(); 
        	printBar();
          mtx1.unlock();
        }
    }
};