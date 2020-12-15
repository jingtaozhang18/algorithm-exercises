// https://leetcode-cn.com/problems/target-sum/
#include<bits/stdc++.h>
using namespace std;

// 划分成两部分A和B
// sumA-sumB=S
// sumA+sumA=S+sumA+sumB
// 2*sumA=S+sumNums
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int acc=0, size=nums.size(),i,j;
        for(int c:nums) acc+=c;
        if(acc<S) return 0; // 限制了tar+acc的范围
        int tar=S+acc;
        if(tar%2) return 0;
        tar>>=1;
        // 转化成子集划分问题，找去其中一部分元素的值使得之和为tar
        vector<vector<int>> dp(size+1, vector<int>(tar+1, 0));
        // 初始化
        dp[0][0]=1;
        for(i=1;i<=size;++i){
            for(j=0;j<=tar;++j){ // 错误点：需要考虑nums中有0的情况。即j-nums[i]=j的时候
                dp[i][j]=dp[i-1][j]; // 不要当前的元素
                if(j-nums[i-1]>=0) dp[i][j]+=dp[i-1][j-nums[i-1]]; // 要当前的元素, 错误点，dp数组左上加了行和列，所以下标对应应该-1
            }
        }
        return dp[size][tar];
    }
};