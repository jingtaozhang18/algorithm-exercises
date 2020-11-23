// https://leetcode-cn.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int i,status=0,ans=0;
        map<int, int> mp; // 倒排索引
        mp[status]=-1;
        for(i=0;i<s.size();++i){
            if(s[i]=='a') status^=1<<0;
            else if(s[i]=='e') status^=1<<1;
            else if(s[i]=='i') status^=1<<2;
            else if(s[i]=='o') status^=1<<3;
            else if(s[i]=='u') status^=1<<4;
            if(mp.find(status)!=mp.end()) {
                ans=max(ans, i-mp[status]);
                // cout<<mp[status]<<" "<<i<<endl;
            }
            else mp[status]=i;
        }
        return ans;
    }
};