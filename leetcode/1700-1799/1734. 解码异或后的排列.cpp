// https://leetcode-cn.com/problems/decode-xored-permutation/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int total=0, odd=0, i, n=encoded.size()+1;
        for(i=1;i<=n;++i) total^=i;
        for(i=1;i<n-1;i+=2) odd^=encoded[i];
        vector<int> ans(n);
        ans[0] = total^odd;
        for(i=1;i<n;++i) ans[i]=encoded[i-1]^ans[i-1];
        return ans;
    }
};