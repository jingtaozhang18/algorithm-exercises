// https://leetcode-cn.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>&coins, int amount, vector<int>& mem){
        if(amount==0) return 0;
        if(amount<0) return -1;
        if(mem[amount]) return mem[amount];
        int ans=INT_MAX,t;
        for(auto c:coins){
            t=jgo(coins, amount-c, mem);
            if(t!=-1) ans=min(ans, 1+t);
        }
        ans=(ans==INT_MAX)?-1:ans;
        mem[amount]=ans;
        // cout<<amount<<": "<<ans<<endl;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mp(amount+1, 0);
        return jgo(coins, amount, mp);
    }
};