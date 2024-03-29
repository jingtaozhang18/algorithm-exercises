// https://leetcode-cn.com/contest/weekly-contest-253/problems/find-the-longest-valid-obstacle-course-at-each-position/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<int, int> mp; // 小于等于key的数量value
    vector<int> del;
    int jcalc(int val){
        int ans;
        auto p=mp.upper_bound(val);
        if(mp.empty()||p==mp.begin()) {
            ans=1;
        }else{
            --p;
            ans=p->second+1;
        }
        mp[val]=ans;
        p=mp.find(val);
        del.clear();
        if(p!=mp.end()) ++p;
        while(p!=mp.end()){
            if(p->second<=ans){
                del.push_back(p->first);
            }else{
                break;
            }
            ++p;
        }
        for(auto &e:del)
            mp.erase(e);
        return ans;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans(obstacles.size());
        int i=0;
        for(auto &e:obstacles){
            ans[i++]=jcalc(e);
        }
        return ans;
    }
};