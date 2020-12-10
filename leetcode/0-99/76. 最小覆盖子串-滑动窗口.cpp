// https://leetcode-cn.com/problems/minimum-window-substring/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        int left=0, right=0, minlen=INT_MAX,ssize=s.size(), tsize=t.size(), ansl; // [left, right)
        for(char c:t) need[c]++;
        while(right<=ssize){
            while(tsize&&right<ssize){
                if(need.find(s[right])!=need.end()) {
                    if(need[s[right]]>0) tsize--;
                    need[s[right]]--;
                }
                right++;
            }
            while(left<=right&&(need.find(s[left])==need.end()||need[s[left]]<0)){
                if(need.find(s[left])!=need.end()) need[s[left]]++;
                left++; 
            }
            if(tsize==0){
                if(right-left<minlen) ansl=left, minlen=right-left;
                if(need[s[left]]==0) tsize++;
                need[s[left]]++, left++;
            }else{
                break;
            }
        }
        return minlen==INT_MAX?"":s.substr(ansl, minlen);
    }
};