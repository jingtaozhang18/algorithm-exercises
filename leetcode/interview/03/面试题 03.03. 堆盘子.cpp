// https://leetcode-cn.com/problems/stack-of-plates-lcci/
#include<bits/stdc++.h>
using namespace std;

class StackOfPlates {
public:
    vector<stack<int>> mem;
    int capbility;
    StackOfPlates(int cap) {
        capbility=cap;
    }
    
    void push(int val) {
        if(!capbility) return; // 错误点，容量为0的时候是不应该有数据插入的
        if(!mem.size()||mem.back().size()==capbility)
        {
            mem.push_back(stack<int>());
        }
        mem.back().push(val);
    }
    
    int pop() {
        if(mem.size()==0) return -1;
        int ans=mem.back().top();
        mem.back().pop();
        while(mem.size() && mem.back().size()==0)
        {
            mem.pop_back();
        }
        return ans;
    }
    
    int popAt(int index) {
        int ans=-1;
        if(index<mem.size())
        {
            if(mem[index].size())
            {
                ans=mem[index].top();
                mem[index].pop();
                if(!mem[index].size())
                {
                    for(int i=index;i<mem.size()-1;++i)
                    {
                        mem[i]=mem[i+1];
                    }
                    mem.pop_back();
                }
            }
        }
        return ans;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */