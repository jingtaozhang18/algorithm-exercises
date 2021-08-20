// https://leetcode-cn.com/problems/meeting-rooms-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> que;
        int ans=0;
        for(auto &meet:intervals){
            while(que.size()&&que.top()<=meet[0]) que.pop();
            que.push(meet[1]);
            ans=ans>que.size()?ans:que.size();
        }
        return ans;
    }
};
