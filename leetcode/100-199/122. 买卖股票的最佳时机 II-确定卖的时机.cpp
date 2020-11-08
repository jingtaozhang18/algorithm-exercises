// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) { // 确定卖的时机
        int i, v_min=prices[0], ans=0;
        for(i=1;i<prices.size();++i){
            v_min=min(v_min, prices[i]);
            if(i==prices.size()-1||prices[i+1]<prices[i]){
                ans+=max(prices[i]-v_min, 0);
                i++;
                if(i<prices.size()) v_min=prices[i];
            }
        }
        return ans;
    }
};