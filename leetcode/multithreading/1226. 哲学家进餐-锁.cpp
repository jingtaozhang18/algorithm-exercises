// https://leetcode-cn.com/problems/the-dining-philosophers/
#include<bits/stdc++.h>
using namespace std;

class DiningPhilosophers {
public:
    mutex lf[5];
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left=philosopher, right=(philosopher+1)%5;
        if(philosopher%2){
            lf[left].lock();
            pickLeftFork();
            lf[right].lock();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
            lf[left].unlock();
            lf[right].unlock();
        }else{
            lf[right].lock();
            pickRightFork();
            lf[left].lock();
            pickLeftFork();
            eat();
            putLeftFork();
            putRightFork();
            lf[left].unlock();
            lf[right].unlock();
        }
    }
};