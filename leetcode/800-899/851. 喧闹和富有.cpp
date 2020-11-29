// https://leetcode-cn.com/problems/loud-and-rich/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<vector<bool>>&gra, vector<int>&color, vector<int>&quiet, vector<int>&ans, int index){
        if(color[index]==2) return ans[index]; // 已经计算到了
        color[index]=1;
        int x=index, y;
        for(int i=0;i<gra.size();++i){
            if(gra[index][i]){
                y=jgo(gra, color, quiet, ans, i);
                if(quiet[y]<quiet[x]) x=y;
            }
        }
        ans[index]=x, color[index]=2;
        return x;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<int> ans(quiet);
        vector<vector<bool>> gra(quiet.size(), vector<bool>(quiet.size(),false));
        for(auto av:richer) gra[av[1]][av[0]]=1;
        vector<int> color(quiet.size(),0); // 0 未探索，1被发现，2已扩展
        for(int i=0;i<quiet.size();++i) jgo(gra, color, quiet, ans, i);
        return ans;
    }
};