// https://leetcode-cn.com/problems/shortest-palindrome/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string shortestPalindrome(string s) {
        int size=2*s.size()+1, i, j, max_len=0;
        string str=string(size, '#');
        for(i=0;i<s.size();++i) str[2*i+1]=s[i];
        vector<int> dp(size, 0);
        int index, pr=-1;
        for(i=0;i<size;++i){
            // 注意这里dp[i]的取值，对应书中的三种情况
            dp[i]=pr>i?min(dp[2*index-i], pr-i):1;
            while(i-dp[i]>=0&&i+dp[i]<size){
                if(str[i-dp[i]]==str[i+dp[i]]) dp[i]++;
                else break;
            }
            if(i+dp[i]>pr) pr=i+dp[i], index=i;
            if(i-dp[i]+1==0||i-dp[i]+1==1) max_len=max(max_len, dp[i]);
        }
        max_len--; // 最终的以0开始的回文串的长度
        // cout<<max_len<<" "<<s.size()<<endl;
        string ans=s.substr(max_len, s.size()-max_len)+s;
        for(i=0,j=s.size()-max_len-1;i<j;++i,--j) swap(ans[i], ans[j]);
        return ans;
    }
};