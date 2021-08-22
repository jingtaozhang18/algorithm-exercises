// https://leetcode-cn.com/problems/min-stack-lcci/
#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> mem;
    stack<int> mmin;
    MinStack() {
      mem=stack<int>();
      mmin=stack<int>();
    }
    
    void push(int x) {
      mem.push(x);
      if(mmin.empty()||mmin.top()>x) mmin.push(x);
      else mmin.push(mmin.top());
    }
    
    void pop() {
      if(mem.empty()) return;
      mem.pop();
      mmin.pop();
    }
    
    int top() {
      if(mem.empty()) return -1;
      return mem.top(); 
    }
    
    int getMin() {
      if(mem.empty()) return -1;
      return mmin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */