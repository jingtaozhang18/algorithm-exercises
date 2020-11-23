// https://leetcode-cn.com/problems/daily-temperatures/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> sta; // 存放坐标
        int i;
        vector<int> ans(T.size(),-1);
        for(i=0;i<T.size();++i){
            while(!sta.empty()&&T[sta.top()]<T[i]){
                ans[sta.top()]=i;
                sta.pop();
            }
            sta.push(i);
        }
        for(i=0;i<T.size();++i){if(ans[i]==-1)ans[i]=0;else ans[i]-=i;}
        return ans;
    }
};