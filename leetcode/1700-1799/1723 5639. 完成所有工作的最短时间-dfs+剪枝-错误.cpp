// https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/
#include<bits/stdc++.h>
using namespace std;

// 错误解答
class Solution {
public:
    int dfs(vector<int>&time, vector<int>&jobs, int k, int index){
        if(index==jobs.size()){return *max_element(time.begin(), time.end());}
        int ans=INT_MAX;
        for(int i=0;i<k;++i){
            if(time[i]+jobs[index]<=ans){
                time[i]+=jobs[index];
                ans=min(ans, dfs(time, jobs, k, index+1));
                time[i]-=jobs[index];
            }
        }
        return ans;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        vector<int> time(jobs.begin(), jobs.begin()+k); // 直接安排了最大的工作均分下去，在[5,5,4,4,4] 2的情况下，无法返回最优解
        return dfs(time, jobs, k, k);
    }
};