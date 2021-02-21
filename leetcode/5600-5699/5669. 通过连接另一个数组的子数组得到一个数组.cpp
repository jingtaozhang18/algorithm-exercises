// https://leetcode-cn.com/contest/biweekly-contest-46/problems/form-array-by-concatenating-subarrays-of-another-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int m=groups.size(), n=nums.size(), i=0, j=0, x, k, size;
        for(i=0;i<m;){
            x=j, k=0, size=groups[i].size();
            for(;j<n&&k<size&&groups[i][k]==nums[j];++j, ++k);
            // cout<<i<<" "<<k<<" "<<size<<endl;
            if(k==size) ++i;
            else if(j==n) return false;
            else j=x+1;
        }
        return true;
    }
};