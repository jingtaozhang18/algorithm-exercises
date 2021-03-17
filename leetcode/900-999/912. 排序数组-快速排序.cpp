// https://leetcode-cn.com/problems/sort-an-array/
#include<bits/stdc++.h>
using namespace std;

#define it vector<int>::iterator 
class Solution {
public:

    it partition(it begin, it end){ // 左闭右开
        it x=end-1;
        swap(*begin, *x);
        it t;
        for(t=begin;t!=x;++t){
            if(*t<*x) {
                swap(*begin, *t); 
                begin++;
            }
        }
        swap(*begin, *x);
        return begin;
    }
    void jsort(it begin, it end){
        if(begin==end||begin+1==end) return; // 错误点: 0个或者一个元素
        it t=partition(begin, end);
        jsort(begin, t);
        jsort(t+1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        jsort(nums.begin(), nums.end());
        return nums;
    }
};