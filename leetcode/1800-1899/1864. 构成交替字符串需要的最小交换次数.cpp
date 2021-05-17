// https://leetcode-cn.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int a=0, b=0, x, y, i, n=s.size();
        for(auto e:s) if(e=='0') ++a; else ++b;
        if(abs(a-b)>1) return -1;
        x=y=0;
        if(a<=b)
            for(i=0;i<n;i++){
                if(i%2==0&&s[i]=='0') ++x; // 1开头
                if(i%2==1&&s[i]!='0') ++x;
            }
        else x=INT_MAX;
        if(a>=b)
            for(i=0;i<n;i++){
                if(i%2==0&&s[i]=='1') ++y;
                if(i%2==1&&s[i]!='1') ++y;
            }
        else y=INT_MAX;
        x=min(x, y);
        return x/2+x%2;
    }
};