// https://leetcode-cn.com/contest/weekly-contest-228/problems/count-number-of-homogenous-substrings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHomogenous(string s) {
        int ans=0, left=0, right=0, size=s.size();
        int t=1e9+7;
        while(right<size){
            ++right;
            if(s[left]!=s[right-1]) left=right-1;
            ans=(right-left+ans)%t;
        }
        return ans;
    }
};