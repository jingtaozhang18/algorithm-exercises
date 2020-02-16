#include<vector>
#include<iostream>
using namespace std;

// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/solution/xu-lie-xing-dong-tai-gui-hua-by-muyids-2/
// dp[i] = Max{dp[i - L] * i} (1 <=L<n, L<=i<=n)
int cuttingRope(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1; // 初始值
    for (int i = 1; i <= (n+1)/2; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = max(dp[j], dp[j-i] * i);
        }
    }
    return dp[n];
}

int main(void){
    cout << cuttingRope(2) << endl;
}