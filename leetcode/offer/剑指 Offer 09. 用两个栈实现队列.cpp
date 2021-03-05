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



// 一个输入栈, 一个输出栈, 保证每个元素最多只会入两次栈, 提升执行效率
class CQueue {
public:
    stack<int> insta, outsta;
    CQueue() {

    }
    
    void appendTail(int value) {
        insta.push(value);
    }
    
    int deleteHead() {
        if(outsta.empty()){
            while(insta.size()){
                outsta.push(insta.top());
                insta.pop();
            }
        }
        if(outsta.empty()) return -1;
        int val = outsta.top();
        outsta.pop();
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */