// https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i, j, size=nums.size();
        for(i=0;i<size;++i){
            while(nums[i]!=i+1&&nums[i]>=1) {
                if(nums[nums[i]-1]==nums[i]) nums[i]=-1;
                else swap(nums[nums[i]-1], nums[i]);
            }
        }
        vector<int> ans;
        for(i=0;i<size;++i) if(nums[i]==-1) ans.push_back(i+1);
        return ans;
    }
};