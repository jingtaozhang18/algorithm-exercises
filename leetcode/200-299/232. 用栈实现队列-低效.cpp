// https://leetcode-cn.com/problems/implement-queue-using-stacks/
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> staa, stab;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(staa.size()) stab.push(staa.top()), staa.pop();
        staa.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(stab.size()) staa.push(stab.top()), stab.pop();
        int val  = staa.top();
        staa.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        while(stab.size()) staa.push(stab.top()), stab.pop();
        return staa.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return staa.empty() && stab.empty();
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