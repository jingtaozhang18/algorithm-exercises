// https://leetcode-cn.com/problems/two-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>& nums, int target){
        for(int i=0;i<nums.size();++i) if(nums[i]==target) return i;
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        vector<int> t(nums);
        sort(t.begin(), t.end());
        int l=0,r=t.size()-1;
        while(l<r){
            if(t[l]+t[r]==target){
                ans[0]=jgo(nums, t[l]);
                ans[1]=jgo(nums, t[r]);
                return ans;
            }else if(t[l]+t[r]>target) r--;
            else l++;
        }
        return ans;
    }
};