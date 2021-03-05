// https://leetcode-cn.com/problems/implement-queue-using-stacks/
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> insta, outsta;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        insta.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outsta.empty()){
            while(insta.size()){
                outsta.push(insta.top());
                insta.pop();
            }
        }
        int val = outsta.top();
        outsta.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        if(outsta.empty()){
            while(insta.size()){
                outsta.push(insta.top());
                insta.pop();
            }
        }
        int val = outsta.top();
        return val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return insta.empty() && outsta.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */