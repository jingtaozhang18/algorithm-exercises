#include<bits/stdc++.h>
using namespace std;

// n个项目，m个工人，每个项目需要使用cost[i]个工人，收益profile[i]
// 在收益大于等于p的情况下的安排方法数
// 工人之间没有区分，都看作是一模一样的
// 测试用例
// 1
// 2 5 3
// 2 2 
// 2 3
// ans
// 2

// 记不清数量范围了，这里开辟的空间需要满足题意空间
int cost[1000];
int profile[1000];
int dp[1000][1000][1000]; // 前i个项目在使用j个工人收益为p的时候的方案数, 收益大于等于p的时候都算p
int mm=1e9+7;
int main(void){
    int t, n, m, p, i, j, k, acc;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &p); // n个项目，m个工人，p的收益
        for(i=0;i<n;++i) scanf("%d", &cost[i]);
        for(i=0;i<n;++i) scanf("%d", &profile[i]);
        for(i=0;i<=n;++i)for(j=0;j<=m;++j)for(k=0;k<=p;++k) dp[i][j][k]=0;
        dp[0][0][0]=1;
        for(i=1;i<=n;++i){
            // 复制上一次的情况，即不做该项目收益相同时的方案数
            for(j=0;j<=m;++j)for(k=0;k<=p;++k) dp[i][j][k]=dp[i-1][j][k];
            for(j=cost[i];j<=m;++j){ // 做当前项目，需要满足工人数量大于等于cost[i]
                for(k=profile[i];k<p;++k){ // 可以影响到profile[i]收益之上的项目
                    dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-cost[i]][k-profile[i]])%mm; // 方案数量等于之前可行的方案数量之和
                }
                for(k=max(0, p-profile[i]);k<=p;++k){ // 大于等于p的方案p的影响，单独考虑
                    dp[i][j][p] = (dp[i][j][p]+dp[i-1][j-cost[i]][k])%mm;
                }
            }
        }
        acc=0;
        for(j=0;j<=m;++j) acc+=dp[n][j][p]; // 所有可行方案数
        printf("%d\n", acc);
    }
    return 0;
}

// 与之类似的一道leetcode题目 [879. 盈利计划](https://leetcode-cn.com/problems/profitable-schemes/)