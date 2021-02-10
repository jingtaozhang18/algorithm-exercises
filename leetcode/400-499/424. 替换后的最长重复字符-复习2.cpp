// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int left=0, right=0, size=s.size(), vmax, ans=0;
        while(right<size){
            vmax=max(vmax, ++map[s[right++]]);
            while(right-left-vmax-k>0) map[s[left++]]--;
            ans=max(ans, right-left);
        }
        return ans;
    }
};