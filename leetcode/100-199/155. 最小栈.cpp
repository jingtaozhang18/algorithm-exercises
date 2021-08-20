// https://leetcode-cn.com/problems/min-stack/
#include <bits/stdc++.h>
using namespace std;

class MinStack {
 public:
  stack<int> sta;
  stack<int> msta;
  MinStack() {}

  void push(int val) {
    if (msta.size() && msta.top() <= val) {
      msta.push(msta.top());
    } else {
      msta.push(val);
    }
    sta.push(val);
  }

  void pop() {
    sta.pop();
    msta.pop();
  }

  int top() { return sta.top(); }

  int getMin() { return msta.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */