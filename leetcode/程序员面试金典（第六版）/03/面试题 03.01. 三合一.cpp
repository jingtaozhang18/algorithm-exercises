// https://leetcode-cn.com/problems/three-in-one-lcci/
#include<bits/stdc++.h>
using namespace std;

class TripleInOne {
public:
    vector<int> mem;
    int size;
    vector<int> index;
    TripleInOne(int stackSize) {
      mem=vector(3*stackSize, 0);
      size=stackSize;
      index=vector<int>{-1,size-1,size*2-1};
    }
    
    void push(int stackNum, int value) {
      if(index[stackNum]==(stackNum+1)*size-1) return ;
      mem[++index[stackNum]]=value;
    }
    
    int pop(int stackNum) {
      if(index[stackNum]==(stackNum)*size-1) return -1;
      else return mem[index[stackNum]--];
    }
    
    int peek(int stackNum) {
      if(index[stackNum]==(stackNum)*size-1) return -1;
      else return mem[index[stackNum]];
    }
    
    bool isEmpty(int stackNum) {
      return index[stackNum]==(stackNum)*size-1;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */