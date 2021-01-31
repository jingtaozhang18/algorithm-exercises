// https://leetcode-cn.com/contest/weekly-contest-226/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<long long> acc;
        int i;
        long long a, b, c;
        acc.push_back(0);
        for(i=0;i<candiesCount.size();++i){
            acc.push_back(acc.back()+candiesCount[i]);
        }
        vector<bool> ans;
        for(auto v:queries){
            a=acc[v[0]]; // 有多少糖果
            b=acc[v[0]+1];
            c=v[2];
            ans.push_back(c*(v[1]+1)>a&&v[1]<b);
        }
        return ans;
    }
};