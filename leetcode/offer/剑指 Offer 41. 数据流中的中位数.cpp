// https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {

    }
    
    void addNum(int num) { // 先插入左侧
        if(left.size()!=right.size()){ // 保存到右侧
            if(num>left.top()) right.push(num);
            else right.push(left.top()), left.pop(), left.push(num);
        }else{
            if(right.empty()) left.push(num);
            else{
                if(num<right.top()) left.push(num);
                else left.push(right.top()), right.pop(), right.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left.size()==right.size()){
            if(left.empty()) return 0;
            else return (double)(left.top()+right.top())/2;
        }else{
            return left.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */