// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) { // 所有区间能赚就赚
        int ans=0,i;
        for(i=1;i<prices.size();++i) ans+=max(0, prices[i]-prices[i-1]);
        return ans;
    }
};