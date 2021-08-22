// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=0,r=nums.size()-1,c;
        while(l<=r){
            c=(l+r)>>1;
            if(nums[c]==c) l=c+1;
            else r=c-1;
        } // 返回时l指向右侧数组的最左，r指向左侧数组的最右
        return l;
    }
};