// https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        int ans=INT_MAX,i,j,t;
        char c;
        for(c='a';c<='z';++c){
            // 相等
            t=0;
            for(i=0;i<a.size();++i) if(a[i]!=c) t++;
            for(j=0;j<b.size();++j) if(b[j]!=c) t++;
            ans=min(ans, t);
            // a < b
            if(c=='a') continue;
            t=0;
            for(i=0;i<a.size();++i) if(a[i]>=c) t++;
            for(j=0;j<b.size();++j) if(b[j]<c) t++;
            ans=min(ans, t);
            t=0;
            for(i=0;i<a.size();++i) if(a[i]<c) t++;
            for(j=0;j<b.size();++j) if(b[j]>=c) t++;
            ans=min(ans, t);
        }
        return ans;
    }
};