// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp; // 统计窗口中出现字母出现的次数
        int left, right, ans=0, t=0; // t 出现次数最多的字符
        for(left=0, right=0;right<s.size();++right){
            mp[s[right]]++;
            t=max(t,mp[s[right]]);
            // 窗口中需要替换的字符数量大于k 缩减
            while(right-left+1-t>k) mp[s[left++ ]]--; // 缩减的是最大数量的字符怎么办？
            // 缩减的如果是最大的字符，则一直等到区间中出现新的出现次数最多的字符，才有效。
            // 其他情况的时候，都没有具体意义，也不会比当前的答案大。
            ans=max(ans, right-left+1);
        }
        return ans;
    }
};