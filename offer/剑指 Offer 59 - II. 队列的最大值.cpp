// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
#include<bits/stdc++.h>
using namespace std;

class MaxQueue {
public:
    deque<int> que_max;
    queue<int> que_con;
    MaxQueue() {

    }
    
    int max_value() {
        if(que_max.empty()) return -1;
        else return que_max.front();
    }
    
    void push_back(int value) {
        que_con.push(value);
        while(!que_max.empty()&&que_max.back()<value) que_max.pop_back();
        que_max.push_back(value);
    }
    
    int pop_front() {
        if(que_con.empty()) return -1;
        int v=que_con.front();
        que_con.pop(); 
        if(v==que_max.front()) que_max.pop_front();
        return v;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */