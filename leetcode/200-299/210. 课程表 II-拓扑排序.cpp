// https://leetcode-cn.com/problems/course-schedule-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> after(numCourses);
        vector<int> nums(numCourses);
        int i;
        for(auto e:prerequisites){
            // e[1] -> e[0]
            after[e[1]].push_back(e[0]);
            nums[e[0]]++;
        }
        vector<int> ans;
        queue<int> que;
        for(i=0;i<numCourses;++i) if(nums[i]==0) que.push(i);
        while(!que.empty()){
            i=que.front();
            que.pop();
            for(auto e:after[i]){
                nums[e]--;
                if(nums[e]==0) que.push(e);
            }
            ans.push_back(i);
        }
        if(ans.size()!=numCourses) return vector<int>();
        return ans;
    }
};