// https://leetcode-cn.com/problems/number-of-substrings-containing-all-three-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=-1,b=-1,c=-1, i, ans=0;
        for(i=0;i<s.size();++i){
            if(s[i]=='a') a=i;
            else if(s[i]=='b') b=i;
            else c=i;
            ans+=min(min(a,b),c)+1;
        }
        return ans;
    }
};
