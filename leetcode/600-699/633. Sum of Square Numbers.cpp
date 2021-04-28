// https://leetcode-cn.com/problems/sum-of-square-numbers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left=0, right=sqrt(c)+1, mul;
        while(left<=right){
            mul=left*left+right*right;
            if(mul==c) return true;
            else if(mul<c){
                ++left;
            }else{
                --right;
            }
        }
        return false;
    }
};