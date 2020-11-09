// https://leetcode-cn.com/problems/palindrome-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> mem;
        int i,j;
        while(x){mem.push_back(x%10); x/=10;}
        for(i=0,j=mem.size()-1;i<j;i++,j--){
            if(mem[i]!=mem[j]) return false;
        }
        return true;
    }
};