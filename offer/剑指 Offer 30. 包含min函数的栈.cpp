// https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> con;
    stack<int> cmin;
    MinStack() {

    }
    
    void push(int x) {
        con.push(x);
        if(cmin.empty()||x<cmin.top()) cmin.push(x);
        else cmin.push(cmin.top());
    }
    
    void pop() {
        con.pop();
        cmin.pop();
    }
    
    int top() {
        return con.top();
    }
    
    int min() {
        return cmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */