// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l,r,ans=0;
        char c;
        set<char> st;
        for(l=-1,r=0;r<s.size();++r){
            c=s[r];
            if(st.find(c)==st.end()){
                ans=max(r-l, ans);
                st.insert(c);
            }else{
                for(++l;s[l]!=c;++l) st.erase(st.find(s[l]));
            }
        }
        return ans;
    }
};