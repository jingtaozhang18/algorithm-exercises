// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        map<char, int> mp; // 计算每个字符最近出现的位置
        vector<int> dp(s.size()); // 位置i结尾的最长子串的长度
        int i,j,ans=1;
        map<char, int>::iterator p;
        dp[0]=1, mp[s[0]]=0; // 初始化
        for(i=1;i<s.size();++i){
            p=mp.find(s[i]);
            dp[i]=min(dp[i-1]+1, i-(p==mp.end()?-1:p->second));
            mp[s[i]]=i, ans=max(ans, dp[i]);
        }
        return ans;
    }
};