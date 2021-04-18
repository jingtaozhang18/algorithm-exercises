// https://leetcode-cn.com/contest/weekly-contest-237/problems/maximum-ice-cream-bars/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        long long sum=0;
        int ans=0;
        for(auto &e:costs){
            sum+=e;
            if(sum<=coins) ans++;
            else break;
        }
        return ans;
    }
};