// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int v_min=prices[0],i,ans=0;
        for(i=1;i<prices.size();++i) 
            ans=max(ans, prices[i]-v_min), v_min=min(v_min, prices[i]);
        return ans; 
    }
};