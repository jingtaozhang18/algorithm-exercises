// https://leetcode-cn.com/problems/get-equal-substrings-within-budget/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i, j, ans=0, size=s.size();
        vector<int> diff(size);
        for(i=0;i<size;++i) diff[i]=abs((int)s[i]-(int)t[i]);
        i=j=0;
        while(j<=size){
            while(j<size&&diff[j]<=maxCost) maxCost-=diff[j++]; // 移动右窗口边界
            ans=max(ans, j-i);
            if(i<j) maxCost+=diff[i++];
            else ++i,++j;
        }
        return ans;
    }
};