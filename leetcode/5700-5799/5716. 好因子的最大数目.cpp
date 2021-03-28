// https://leetcode-cn.com/problems/maximize-number-of-nice-divisors/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        long long ans=1, mod=1e9+7;
        int a = primeFactors / 3;
        int b = primeFactors % 3;
        cout<<a<<" "<<b<<endl;
        if(b==1) a--, b=4;
        else if(b==0) b=1;
        cout<<a<<" "<<b<<endl;
        for(int i=0;i<a;++i) ans*=3, ans%=mod;
        ans*=b, ans%=mod;
        return ans;
    }
};