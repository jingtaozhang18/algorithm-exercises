// https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        unsigned int t=0, i;
        vector<bool> ans;
        for(i=0;i<A.size();++i){
            t=(((unsigned int)t<<1)+A[i])%5;
            ans.push_back(t==0);
        }
        return ans;
    }
};