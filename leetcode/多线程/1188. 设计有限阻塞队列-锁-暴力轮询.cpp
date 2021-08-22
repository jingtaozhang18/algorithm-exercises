// https://leetcode-cn.com/problems/design-bounded-blocking-queue/submissions/
#include<bits/stdc++.h>
using namespace std;

class BoundedBlockingQueue {
public:
    mutex n_lock, full_lock, empty_lock;
    int n, _size;
    queue<int> que;
    BoundedBlockingQueue(int capacity) {
        n=0;
        _size=capacity;
    }
    
    void enqueue(int element) {
        n_lock.lock();
        while(n>=_size){ // 暴力轮询
          n_lock.unlock();
        //   full_lock.lock();
          n_lock.lock();
        }
        ++n;
        que.push(element);
        // cout<<"push: "<<element<<endl;
        // if(n==1) empty_lock.unlock();
        n_lock.unlock();
    }
    
    int dequeue() {
        int ans;
        n_lock.lock();
        while(n==0){
            n_lock.unlock(); // 暴力轮询
            // empty_lock.lock();
            n_lock.lock();
        }
        --n;
        ans=que.front();
        que.pop();
        // cout<<"pop: "<<ans<<endl;
        // if(n<_size) empty_lock.unlock();
        n_lock.unlock();
        return ans;
    }
    
    int size() {
        int ans;
        n_lock.lock();
        ans=n;
        n_lock.unlock();
        return ans;
    }
};