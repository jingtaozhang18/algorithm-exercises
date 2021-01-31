// https://leetcode-cn.com/problems/longest-palindromic-substring/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      int i,size=2*s.size()+1;
      string t=string(size, '#');
      for(i=0;i<s.size();++i) t[2*i+1]=s[i]; // 插入#字符
      vector<int> dp(size, 0); // 半径范围包括自己
      int index, pr=-1, max_len=0, max_index=0;
      for(i=0;i<size;++i){
        dp[i]=pr>i?min(dp[2*index-i], pr-i):1;
        while(i+dp[i]<size&&i-dp[i]>=0){
          if(t[i+dp[i]]==t[i-dp[i]]) dp[i]++;
          else break;
        }
        if(dp[i]+i>pr) pr=dp[i]+i, index=i;
        if(dp[i]>max_len) max_len=dp[i], max_index=i;
      }
      max_len--;
      max_index=(max_index-max_len)/2;
      return s.substr(max_index, max_len);
    }
};