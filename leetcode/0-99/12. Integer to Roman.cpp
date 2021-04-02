// https://leetcode-cn.com/problems/integer-to-roman/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int level[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string label[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        string s;
        int i;
        while(num){
            for(i=12;i>=0&&level[i]>num;--i);
            s+=label[i];
            num-=level[i];
        }
        return s;
    }
};