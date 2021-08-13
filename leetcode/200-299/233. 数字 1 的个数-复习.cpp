// https://leetcode-cn.com/problems/number-of-digit-one/
#include<bits/stdc++.h>
using namespace std;

long max(long a, long b){
    return a>b?a:b;
}
long min(long a, long b){
    return a>b?b:a;
}
class Solution {
public:
    int countDigitOne(int n) {
        long pb=1, base=10, ans=0;
        while(pb<=n){
            ans += n/base*pb;
            ans += max(min(n%base, pb*2-1)-pb+1, 0);
            pb = base;
            base *=10;
        }
        return ans;
    }
};
