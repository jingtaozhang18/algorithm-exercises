// https://leetcode-cn.com/problems/continuous-median-lcci/
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> maxp;
    priority_queue<int, vector<int>, greater<int>> minp;
    MedianFinder() {

    }
    
    void addNum(int num) {
      if(maxp.size()<=minp.size()) maxp.push(num);
      else minp.push(num);
      if(!minp.empty()&&maxp.top()>minp.top()){ // 错误点: 判断top是否存在
        int a=maxp.top();maxp.pop();
        int b=minp.top();minp.pop();
        maxp.push(b);
        minp.push(a);
      }
    }
    
    double findMedian() {
      if(maxp.empty()) return -1;
      if(maxp.size()==minp.size()) return ((double)(maxp.top()+minp.top()))/2;
      else return maxp.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */