// https://leetcode-cn.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag=true;
        int i, n=s.size();
        for(i=0;i<n;++i){
            if(flag&&s[i]=='0') flag=false;
            else if(!flag&&s[i]=='1') return false;
        }
        return true;
    }
};