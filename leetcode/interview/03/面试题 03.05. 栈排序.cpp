// https://leetcode-cn.com/problems/sort-of-stacks-lcci/
#include<bits/stdc++.h>
using namespace std;

class SortedStack {
public:
    stack<int> sta;
    stack<int> tmp;
    SortedStack() {

    }
    
    void push(int val) {
        while(!sta.empty()&&sta.top()<val) 
        {
            tmp.push(sta.top());
            sta.pop();
        }
        while(!tmp.empty()&&tmp.top()>val) 
        {
            sta.push(tmp.top());
            tmp.pop();
        }
        sta.push(val);
    }
    
    void pop() {
        while(!tmp.empty())
        {
            sta.push(tmp.top());
            tmp.pop();
        }
        if(!sta.empty()) sta.pop();
    }
    
    int peek() {
        while(!tmp.empty())
        {
            sta.push(tmp.top());
            tmp.pop();
        }
        return sta.empty()?-1:sta.top();
    }
    
    bool isEmpty() {
        return sta.empty()&&tmp.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */