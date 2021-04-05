// https://leetcode-cn.com/problems/longest-valid-parentheses/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int i, j, n=s.size();
        if(n==0) return 0;
        int dp[n], ans=0; // dp[i] 以i结尾的最长长度
        for(i=0;i<n;++i) dp[i]=0;
        for(i=0;i<n;++i){
            if(s[i]==')'){
                for(j=i-1;j>=0&&dp[j]!=0;j-=dp[j]); // 找到最远没有被匹配上的位置
                if(j>=0&&s[j]=='(') dp[i]=(j>0?dp[j-1]:0)+i-j+1;
                else dp[i]=0;
            }else{
                dp[i]=0;
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};