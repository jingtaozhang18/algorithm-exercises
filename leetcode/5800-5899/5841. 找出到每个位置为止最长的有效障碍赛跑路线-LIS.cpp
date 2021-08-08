// https://leetcode-cn.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> tis;
        vector<int> ans(obstacles.size());
        int i=0;
        for(auto &obstacle:obstacles){
            auto p = upper_bound(tis.begin(), tis.end(), obstacle);
            if(p==tis.end()){
                tis.emplace_back(obstacle);
                ans[i]=tis.size();
            }else{
                (*p) = obstacle;
                ans[i]=p-tis.begin()+1;
            }
            ++i;
        }
        return ans;
    }
};