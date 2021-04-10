// https://leetcode-cn.com/problems/t3fKg1/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int processTasks(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end());
        tasks.push_back(vector<int>{1000000005, 1000000005, 1});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int res=0; // 运行时间
        for(auto &t:tasks){
            while(que.size()&&que.top().first+res<t[0]){ // 
                if(que.top().first+res>=que.top().second) que.pop(); // 该任务运行结束了
                else res+=min(que.top().second, t[0])-(que.top().first+res);
            }
            // <任务最晚开始的时间， 任务结束的时间>
            que.push({t[1]-t[2]+1-res,t[1]+1});
        }
        return res;
    }
};