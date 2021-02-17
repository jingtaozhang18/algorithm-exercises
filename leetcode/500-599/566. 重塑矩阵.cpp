// https://leetcode-cn.com/problems/reshape-the-matrix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size(), n=nums[0].size(), i;
        if(r*c!=m*n) return nums;
        vector<vector<int>> ans(r, vector<int>(c));
        for(i=0;i<m*n;++i){
            ans[i/c][i%c]=nums[i/n][i%n];
        }
        return ans;
    }
};