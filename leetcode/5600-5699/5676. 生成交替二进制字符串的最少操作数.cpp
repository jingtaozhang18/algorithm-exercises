// https://leetcode-cn.com/contest/weekly-contest-228/problems/minimum-changes-to-make-alternating-binary-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int i, size=s.size(), ans=0, t=0;
        for(i=0;i<size;++i){
            if(i%2==0 && s[i]=='0') t++;
            if(i%2==1 && s[i]=='1') t++;
        }
        ans=t, t=0;
        for(i=0;i<size;++i){
            if(i%2==0 && s[i]=='1') t++;
            if(i%2==1 && s[i]=='0') t++;
        }
        return min(ans, t);
    }
};