// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i=0,j=nums.size()-1,t;
        while(i<j){
            if(nums[i]%2)++i;
            else t=nums[i], nums[i]=nums[j], nums[j]=t, --j;
        }
        return nums;
    }
};