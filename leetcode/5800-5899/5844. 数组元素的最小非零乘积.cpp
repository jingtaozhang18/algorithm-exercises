// https://leetcode-cn.com/problems/minimum-non-zero-product-of-the-array-elements/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNonZeroProduct(int p) {
        if(p==1) return 1;
        long long x = 1, mod=1e9+7, ans=1;
        long long y = (((x<<p)-2)%mod);
        for(int i=0;i<p-1;++i){
            ans*=y;
            ans%=mod;
            y*=y;
            y%=mod;
        }
        ans*=(((x<<p)-1)%mod);
        ans%=mod;
        return ans;
    }
};