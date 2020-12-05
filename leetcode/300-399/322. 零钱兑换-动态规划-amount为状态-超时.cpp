// https://leetcode-cn.com/problems/coin-change/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(amount<0) return -1;
        int ans=INT_MAX,t;
        for(auto c:coins){
            t=coinChange(coins, amount-c);
            if(t!=-1) ans=min(ans, 1+t);
        }
        return ans==INT_MAX?-1:ans;
    }
};