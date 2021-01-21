// https://leetcode-cn.com/problems/course-schedule/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<vector<int>> before(numCourses); // 选修i课程的前序课程
        vector<vector<int>> after(numCourses); // i课程之后的课程
        vector<int> nums(numCourses); // 之前需要的课程数量
        int i,ans=0;
        // 构建信息
        for(auto e:prerequisites){
            // e[1]->e[0]
            after[e[1]].push_back(e[0]);
            // before[e[0]].push_back(e[1]);
            nums[e[0]]++;
        }
        queue<int> que;
        for(i=0;i<numCourses;++i) if(nums[i]==0) que.push(i);
        while(!que.empty()){
            i=que.front();
            que.pop();
            ans++;
            for(auto e:after[i]) {
                nums[e]--;
                if(nums[e]==0) que.push(e);
            }
        }
        return ans==numCourses;
    }
};