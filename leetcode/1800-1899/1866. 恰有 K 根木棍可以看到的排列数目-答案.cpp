// https://leetcode-cn.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    static constexpr int mod = 1000000007;
    
public:
    int rearrangeSticks(int n, int k) {
        vector<int> f(k + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> g(k + 1);
            for (int j = 1; j <= k; ++j) {
                g[j] = ((long long)f[j] * (i - 1) % mod + f[j - 1]) % mod;
            }
            f = move(g);
        }
        return f[k];
    }
};