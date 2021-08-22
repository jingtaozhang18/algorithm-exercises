// https://leetcode-cn.com/problems/design-bounded-blocking-queue/
#include<queue>
#include<semaphore.h>
#include<bits/stdc++.h>
using namespace std;

class BoundedBlockingQueue {
public:
    
    sem_t p, c, mut;
    queue<int> q;
    
    BoundedBlockingQueue(int capacity) {
        sem_init(&p, 0, capacity);
        sem_init(&c, 0, 0);
        sem_init(&mut, 0, 1);
    }
    
    void enqueue(int element) {
        sem_wait(&p);
        sem_wait(&mut);
        q.push(element);
        sem_post(&mut);
        sem_post(&c);
    }
    
    int dequeue() {
        
        sem_wait(&c);
        sem_wait(&mut);
        int ans = q.front();
        q.pop();
        sem_post(&mut);
        sem_post(&p);
        return ans;
    }
    
    int size() {
        sem_wait(&mut);
        int ans = q.size();
        sem_post(&mut);
        return ans;
    }
};