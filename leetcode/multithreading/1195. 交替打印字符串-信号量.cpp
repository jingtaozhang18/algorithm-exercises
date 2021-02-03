// https://leetcode-cn.com/problems/fizz-buzz-multithreaded/
#include<bits/stdc++.h>
#include <semaphore.h>
using namespace std;

class FizzBuzz {
private:
    int n;
    int cur;
    sem_t sem_fizz;
    sem_t sem_buzz;
    sem_t sem_fizz_buzz;
    sem_t sem_num;

public:
    FizzBuzz(int n) {
        this->n = n;
        cur = 1;
        sem_init(&sem_fizz, 0, 0);
        sem_init(&sem_buzz, 0, 0);
        sem_init(&sem_fizz_buzz, 0, 0);
        sem_init(&sem_num, 0, 1); // 第一个0表示只允许在进程中共享
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(cur <= n){
            sem_wait(&sem_fizz);
            if(cur > n) break;
            printFizz();
            sem_post(&sem_num);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(cur <= n){
            sem_wait(&sem_buzz);
            if(cur > n) break;
            printBuzz();
            sem_post(&sem_num);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(cur <= n){
            sem_wait(&sem_fizz_buzz);
            if(cur > n) break;
            printFizzBuzz();
            sem_post(&sem_num);
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(cur <= n){
            if(cur % 3 == 0 && cur % 5 == 0){
                sem_post(&sem_fizz_buzz);
            }else if(cur % 3 == 0){
                sem_post(&sem_fizz);
            }else if(cur % 5 == 0){
                sem_post(&sem_buzz);
            }else{
                printNumber(cur);
                sem_post(&sem_num);
            }
            sem_wait(&sem_num); // 等待信号量
            ++cur;
        }
        // 以下三个post通过更新sem_fizz等信号量，调动其他线程运行，进而结束所有线程
        sem_post(&sem_fizz);
        sem_post(&sem_buzz);
        sem_post(&sem_fizz_buzz);
    }
};