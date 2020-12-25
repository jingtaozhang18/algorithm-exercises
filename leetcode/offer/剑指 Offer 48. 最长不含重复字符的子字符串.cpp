// https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        vector<int> record(200, -1); // 记录每个字符最后出现的位置
        vector<int> dp(s.size(), 1); // 记录以位置i结尾的最大长度
        int i, ans=1;
        record[s[0]]=0;
        for(i=1;i<s.length();++i){
            if(record[s[i]]==-1) dp[i]=dp[i-1]+1;
            else dp[i]=min(i-record[s[i]], dp[i-1]+1); // 因为只用到了dp[i-1], 可以使用空间压缩的思想，进行简化
            record[s[i]]=i, ans=max(ans, dp[i]);
        }
        return ans;
    }
};