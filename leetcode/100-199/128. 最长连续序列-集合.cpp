// https://leetcode-cn.com/problems/longest-consecutive-sequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int i,ans=0,j,k;
        for(i=0;i<nums.size();++i){
            if(st.find(nums[i]-1)==st.end()){
                for(j=nums[i],k=0;st.find(j)!=st.end();++j,++k);
                ans=max(ans, k);
            }
        }
        return ans;
    }
};