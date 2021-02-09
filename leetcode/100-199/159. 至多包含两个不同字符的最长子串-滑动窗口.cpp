// https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left=0, right=0, size=s.size(), ans=0;
        unordered_map<char, int> map;
        while(right<size){
            ++map[s[right++]];
            while(map.size()>2){
                --map[s[left]];
                if(map[s[left]]==0) 
                    map.erase(s[left]);
                ++left;
            }
            ans=max(ans, right-left);
        }
        return ans;
    }
};