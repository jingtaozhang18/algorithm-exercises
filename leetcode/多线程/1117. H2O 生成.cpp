// https://leetcode-cn.com/problems/building-h2o/
#include<bits/stdc++.h>
using namespace std;

// 学习题解
class Semaphore {
private:
    int n_;
    mutex mu_;
    // A condition variable is an object able to block the calling thread until notified to resume.
    condition_variable cv_;

public:
    Semaphore(int n): n_{n} {}

public:
    void wait() {
        unique_lock<mutex> lock(mu_); // 
        if (!n_) {
            cv_.wait(lock, [this]{return n_;});
        }
        --n_;
    }

    void signal() {
        unique_lock<mutex> lock(mu_);
        ++n_;
        cv_.notify_one();
    }
};

class H2O {
public:
private:
    Semaphore h_p, o_p, h_b, o_b;
public:
    H2O():h_p{2}, o_p{1}, h_b{0}, o_b{0} {}
    // 思路
    // 获得生产的权力 -> 等待对方的到来，被允许生产 -> 生产 -> 释放生产的权力
    void hydrogen(function<void()> releaseHydrogen) {
        h_p.wait(); // 消耗一个生产H的权力，进入等待生产的阶段
        // 打破O的一个壁垒，一个O需要两个H来打破壁垒
        o_b.signal();
        // 等待O来打破H的壁垒
        h_b.wait();
        // 生产
        releaseHydrogen();
        h_p.signal();
    }

    void oxygen(function<void()> releaseOxygen) {
        o_p.wait(); // 消耗一个生产O的权力，进入等待生产的阶段
        // 等待两个H来打破壁垒
        o_b.wait();
        o_b.wait();
        // 打破两个H的壁垒
        h_b.signal();
        h_b.signal();
        // 生产
        releaseOxygen();
        // 恢复O的生产权力
        o_p.signal();
    }
};