// https://leetcode-cn.com/problems/print-in-order/
#include<bits/stdc++.h>
using namespace std;

class Foo {
public:
    // 使用锁来 lock(获得锁)和unlock(解开锁)
    mutex mtx1, mtx2;
    Foo() {
        mtx1.lock(), mtx2.lock();
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        mtx1.unlock();
    }

    void second(function<void()> printSecond) {
        mtx1.lock(); // 需要获得锁
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        mtx1.unlock();
        mtx2.unlock();
    }

    void third(function<void()> printThird) {
        mtx2.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        mtx2.unlock();
    }
};