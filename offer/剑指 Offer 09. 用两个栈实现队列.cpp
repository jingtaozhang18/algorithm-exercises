// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
#include<bits/stdc++.h>
using namespace std;

class CQueue {
public:
    stack<int> head;
    stack<int> tail;

    CQueue() {

    }
    
    void appendTail(int value) {
        while(!tail.empty()){
            head.push(tail.top());
            tail.pop();
        }
        tail.push(value);
    }
    
    int deleteHead() {
        while(!head.empty()){
            tail.push(head.top());
            head.pop();
        }
        if(tail.empty()) return -1;
        int ans=tail.top();
        tail.pop();
        return ans;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */