// https://leetcode-cn.com/problems/interleaving-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(string& s1, string& s2, string& s3, int i, int j, int k){
        if(k==s3.size()) return true;
        if(i<s1.size()&&s1[i]==s3[k]) if(jgo(s1,s2,s3,i+1,j,k+1)) return true;
        if(j<s2.size()&&s2[j]==s3[k]) if(jgo(s1,s2,s3,i,j+1,k+1)) return true;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        return jgo(s1, s2, s3, 0, 0, 0);
    }
};