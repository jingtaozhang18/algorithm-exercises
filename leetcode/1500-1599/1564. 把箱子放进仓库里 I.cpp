// https://leetcode-cn.com/problems/put-boxes-into-the-warehouse-i/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        stack<int> sta;
        int i,ans=0;
        for(auto x:warehouse){
            if(sta.empty()||x<=sta.top()) sta.push(x);
            else sta.push(sta.top());
        }
        sort(boxes.begin(), boxes.end());
        for(i=0;i<boxes.size()&&!sta.empty();++i){
            while(!sta.empty()&&sta.top()<boxes[i]) sta.pop();
            if(!sta.empty()){ans++; sta.pop();}
        }
        return ans;
    }
};