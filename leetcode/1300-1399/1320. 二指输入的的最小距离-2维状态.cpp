// https://leetcode-cn.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calc(int a, int b){
        int ax=a/6, ay=a%6, bx=b/6, by=b%6;
        int diff_a=ax-bx, diff_b=ay-by;
        if(diff_a<0) diff_a=-diff_a;
        if(diff_b<0) diff_b=-diff_b;
        return diff_a+diff_b;
    }
    int minimumDistance(string word) {
        // dp[i][k] 第i-1个字符时，一个手指头在word[i-1], 另一个手指头在i-1字符位置时的移动最少移动步数
        int dp[301][26], i, j, k, prev, v, n=word.size(), ans=INT_MAX; 
        for(i=0;i<=n;++i){
            for(k=0;k<26;++k){
                if(i<=1) dp[i][k]=0; // 初始化随意放
                else dp[i][k]=INT_MAX-20;
            }
        }
        for(i=2;i<=n;++i){
            v = word[i-1]-'A';
            prev = word[i-2]-'A';
            for(k=0;k<26;++k){
                dp[i][k] = min(dp[i][k], dp[i-1][k]+calc(prev, v)); // 上次按中的手指这次继续去按
                dp[i][prev] = min(dp[i][prev], dp[i-1][k]+calc(k, v)); // 上次没有按的手指这次去按, 按中的手值这次就没有按中，放到了prev的位置
                if(i==n){
                    ans=min(ans, dp[i][k]);
                    ans=min(ans, dp[i][prev]);
                }
            }
        }
        return ans;
    }
};