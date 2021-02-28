// https://leetcode-cn.com/problems/range-sum-query-immutable/
#include<bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> arr;
public:
    NumArray(vector<int>& nums) {
        arr=vector<int>(nums.size()+1);
        for(int i=1;i<=nums.size();++i){
            arr[i]=arr[i-1]+nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return arr[j+1]-arr[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */