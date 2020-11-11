// https://leetcode-cn.com/problems/longest-palindromic-substring/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        // 动态规划 s[i..j]是否是回文串
        int len=s.size(),i,j,d,mav=1,a=0,b=0;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        for(i=0;i<len;++i) dp[i][i]=true;
        for(d=1;d<len;++d){
            for(i=0;i<len-d;++i){
                j=i+d;
                if(s[i]==s[j]&&(dp[i+1][j-1]||j-i==1)) dp[i][j]=true; // 中间没有元素或者中间的元素是回文
                if(dp[i][j]&&(j-i+1)>mav) mav=j-i+1,a=i,b=j;
            }
        }
        return s.substr(a,b-a+1);
    }
};