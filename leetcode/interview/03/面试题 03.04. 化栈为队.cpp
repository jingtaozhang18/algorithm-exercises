// https://leetcode-cn.com/problems/implement-queue-using-stacks-lcci/
#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> sa;
    stack<int> sb;

    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!sb.empty()) {sa.push(sb.top()); sb.pop();}
        sb.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!sa.empty()) {sb.push(sa.top()); sa.pop();}
        if(sb.empty()) return -1;
        int ans=sb.top();
        sb.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        while(!sa.empty()) {sb.push(sa.top()); sa.pop();}
        if(sb.empty()) return -1;
        return sb.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sa.empty()&&sb.empty();
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
