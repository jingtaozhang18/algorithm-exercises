// https://leetcode-cn.com/problems/flatten-nested-list-iterator/
#include<bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
 

class NestedIterator {
public:
    vector<NestedInteger> mem;
    stack<int> sta; // 当前指针的下标
    stack<vector<NestedInteger> *> ptr; // 访问的指针
    NestedIterator(vector<NestedInteger> &nestedList) {
        mem = vector<NestedInteger>(nestedList);
        if(mem.size()==0) return;
        sta.push(0);
        ptr.push(&mem);
        while(ptr.size()&&(*ptr.top())[sta.top()].isInteger() == false){
            if((*ptr.top())[sta.top()].getList().size()==0){
                ++sta.top();
                while(sta.size()&&sta.top()==ptr.top()->size()){ // 没有元素了
                    sta.pop(), ptr.pop();
                    if(sta.size()) ++sta.top();
                }
            }else{
                ptr.push( &( (*ptr.top())[sta.top()].getList() ) );
                sta.push(0);
            }
        }
        // 接受
    }
    
    int next() {
        int ans = (*ptr.top())[sta.top()].getInteger();
        while(sta.size()&&sta.top()==ptr.top()->size()-1){ // 最后一个元素了
            ptr.pop(); sta.pop();
        }
        if(sta.size()){
            ++sta.top(); // 更新下标
            while(ptr.size()&&(*ptr.top())[sta.top()].isInteger() == false){
                if((*ptr.top())[sta.top()].getList().size()==0){
                    ++sta.top();
                    while(sta.size()&&sta.top()==ptr.top()->size()){ // 没有元素了
                        sta.pop(), ptr.pop();
                        if(sta.size()) ++sta.top();
                    }
                }else{
                    ptr.push( &( (*ptr.top())[sta.top()].getList() ) );
                    sta.push(0);
                }
            }
        }
        return ans;
    }
    
    bool hasNext() {
        return sta.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */