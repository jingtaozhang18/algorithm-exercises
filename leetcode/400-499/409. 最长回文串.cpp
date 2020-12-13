// https://leetcode-cn.com/problems/longest-palindrome/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(char c:s) mp[c]++;
        int ans=0; bool sig=false;
        for(auto p=mp.begin();p!=mp.end();++p){
            sig=sig||p->second%2;
            ans+=(p->second>>1<<1);
        }
        ans+=sig?1:0;
        return ans;
    }
};