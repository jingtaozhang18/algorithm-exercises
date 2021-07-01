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

// 复习
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int i=0, acc=0;
        for(;i<costs.size()&&acc<=coins;++i) 
            acc+=costs[i];
        if(acc>coins) return i-1;
        else return i;
    }
};
