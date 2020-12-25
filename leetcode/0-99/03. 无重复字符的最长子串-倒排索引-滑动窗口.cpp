// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l,r,ans=0;
        unordered_map<char, int> mp; // 注意，没有必要排序的时候，使用 unordered_map
        unordered_map<char, int>::iterator p;
        for(l=-1,r=0;r<s.size();++r){
            p=mp.find(s[r]);
            if(p!=mp.end()) l=max(l, p->second); // 体现滑动窗口的地方，只能向右不能向左
            ans=max(r-l, ans);
            mp[s[r]]=r;
        }
        return ans;
    }
};