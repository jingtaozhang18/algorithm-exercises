// https://leetcode-cn.com/problems/bianry-number-to-string-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string printBin(double num) {
        string ans="0.";
        for(int i=0;i<30;++i){ // 32位之内，0.占了两位，这个得再学学
            num*=2;
            if(num==0) return ans;
            else if(num>=1) ans+='1', num-=1;
            else if(num>0&&num<1) ans+='0';
        }
        return "ERROR";
    }
};