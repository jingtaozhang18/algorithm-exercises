// https://leetcode-cn.com/contest/weekly-contest-253/problems/minimum-number-of-swaps-to-make-the-string-balanced/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int sum=0;
        for(auto &c:s){
            if(c=='['){
                sum++;
            }else{
                if(sum>0)
                    sum--;
            }
        }
        return sum/2+(sum%2==1?1:0);
    }
};