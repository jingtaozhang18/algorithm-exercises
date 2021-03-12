// https://leetcode-cn.com/problems/merge-intervals/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start, end;
        for(int i=0;i<=intervals.size();++i){
            if(i==0){
                start=intervals[i][0];
                end=intervals[i][1];
            }else{
                if(i==intervals.size()||intervals[i][0]>end){
                    ans.push_back(vector<int>{start, end});
                    if(i!=intervals.size()) start=intervals[i][0], end=intervals[i][1];
                }else{
                    end=max(end, intervals[i][1]); //  [1, 4], [2, 3]
                }
            }
        }
        return ans;
    }
};