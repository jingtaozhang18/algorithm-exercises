// https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int i,j,size=nums.size(),len=1,ans=1,a,b;
        if(!size) return 0;
        vector<int> dp(size);
        vector<int> kind(size); // 记录以该数字结尾的最长子序列的种类数
        dp[0]=1, kind[0]=1;
        for(i=1;i<size;++i){
            for(j=0,a=INT_MIN;j<i;++j){
                if(nums[j]<nums[i]){
                    if(dp[j]>a){a=dp[j], b=kind[j];}
                    else if(dp[j]==a) b+=kind[j];
                }
            }
            if(a==INT_MIN) dp[i]=kind[i]=1;
            else dp[i]=a+1, kind[i]=b;
            if(dp[i]>len) len=dp[i], ans=kind[i];
            else if(dp[i]==len) ans+=kind[i];
        }
        return ans;
    }
};