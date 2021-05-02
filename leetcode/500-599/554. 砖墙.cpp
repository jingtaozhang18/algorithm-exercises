// https://leetcode-cn.com/problems/brick-wall/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int i, j, acc, n=wall.size();
        unordered_map<int, int> map;
        for(i=0;i<n;++i){
            for(acc=0, j=0;j<wall[i].size()-1;++j){
                acc+=wall[i][j];
                map[acc]++;
            }
        }
        int ans=0;
        for(auto &p:map){
            ans=max(ans, p.second);
        }
        return n-ans;
    }
};