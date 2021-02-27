// https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(string& s, int start, int end, int k){ // [start, end)范围中的最优解
        // cout<<start<<" "<<end<<endl;
        int i, j, ans=0;
        if(start>=end) return 0;
        if(start+1==end) return k<=1?1:0;
        char c;
        unordered_map<char, int> mp;
        unordered_set<char> st;
        for(i=start;i<end;++i){ // 为s中的字符编号，出现了第几次
            mp[s[i]]++;
        }
        for(auto p:mp){
            if(p.second<k){
                st.insert(p.first);
            }
        }
        if(st.empty()) return end-start;
        else {
            i=start, ans=0;
            for(j=start;j<=end;++j){
                if(j==end||st.count(s[j])){
                    ans=max(ans, jgo(s, i, j, k));
                    i=j+1;
                }
            }
        }
        return ans;
    }
    int longestSubstring(string s, int k) {
        return jgo(s, 0, s.size(), k);
    }
};