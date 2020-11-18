// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> mp; // 统计窗口中出现字母出现的次数
        int left, right, ans=0, t=0; // t 出现次数最多的字符
        for(left=0, right=0;right<s.size();++right){
            mp[s[right]]++;
            t=max(t,mp[s[right]]);
            // 窗口中需要替换的字符数量大于k 缩减
            // 重点：在保证不超合法长度的条件下尽可能的保持长度
            while(right-left+1-t>k) mp[s[left++ ]]--;
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};