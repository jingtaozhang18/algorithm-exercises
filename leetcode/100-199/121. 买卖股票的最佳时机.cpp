// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int miv=prices[0], i, ans=0;
        for(i=1;i<prices.size();++i) ans=max(ans, prices[i]-miv), miv=min(miv, prices[i]);
        return ans;
    }
};