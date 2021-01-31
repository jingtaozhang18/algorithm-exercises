// https://leetcode-cn.com/contest/weekly-contest-226/problems/restore-the-array-from-adjacent-pairs/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> map;
        int start, father;
        for(auto e:adjacentPairs){
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }
        for(auto p:map) if(p.second.size()==1) {start=p.first; break;}
        vector<int> ans;
        ans.push_back(start);
        father=start, start=map[start][0];
        while(map[start].size()==2){
            ans.push_back(start);
            if(map[start][0]==father){father=start, start=map[start][1];}
            else{father=start, start=map[start][0];}
        }
        ans.push_back(start);
        return ans;
    }
};