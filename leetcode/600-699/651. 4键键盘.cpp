// https://leetcode-cn.com/problems/4-keys-keyboard/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxA(int n) {
        int i, j;
        vector<int> dp(n+1, 0);
        for(i=1;i<=n;++i){
            dp[i]=dp[i-1]+1; // 这次按的是A
            for(j=2;j<i;++j){ // 上次按完ctrl+a&ctrl+v的时间
                // 这里需要注意一下，dp[j-2]从j>2开始，其值就是>=1, 所以之后一定是连续按ctrl-v更划算
                dp[i]=max(dp[i], dp[j-2]*(i-j+1));
            }
        }
        return dp[n];
    }
};