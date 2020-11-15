// https://leetcode-cn.com/problems/burst-balloons/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>&nums, int i){
        if(i==-1||i==nums.size()) return 1;
        return nums[i];
    }
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int size=nums.size(),i,j,k,t;
        // [i][j] 戳破i到j范围的气球可以获得的最大收益,且i-1和j+1的气球都在
        vector<vector<int>> dp(size, vector<int>(size, 0)); 
        // 初始化对角线
        for(i=0;i<size;++i) dp[i][i]=jgo(nums,i-1)*jgo(nums,i)*jgo(nums,i+1);
        for(i=1;i<size;++i){ // 间隔
            for(j=0;j+i<size;++j){ // [j, j+i]
                t=jgo(nums,j)*jgo(nums,j-1)*jgo(nums,j+i+1)+dp[j+1][j+i]; // 最后戳中j
                t=max(t, jgo(nums,j+i)*jgo(nums,j-1)*jgo(nums,j+i+1)+dp[j][j+i-1]); // 最后戳中j+i
                for(k=j+1;k<j+i;++k) t=max(t, dp[j][k-1]+dp[k+1][j+i]+jgo(nums,k)*jgo(nums,j-1)*jgo(nums,j+i+1));
                dp[j][j+i]=t;
            }
        }
        return dp[0][size-1];
    }
};