// https://leetcode-cn.com/problems/plus-one/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int acc=0, i, x, add=1, n=digits.size();
        for(i=n-1;i>=0&&(add||acc);--i){
            x = digits[i]+add+acc;
            digits[i] = x%10;
            acc = x/10;
            add = 0;
        }
        if(acc){
            digits.push_back(0);
            for(i=n-1;i>=0;--i) digits[i+1]=digits[i];
            digits[0]=1;
        }
        return digits;
    }
};