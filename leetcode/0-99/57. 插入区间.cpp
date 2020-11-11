// https://leetcode-cn.com/problems/insert-interval/	
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<vector<int>>& nums, int t){ // 找t出现在的区间内
        int l=0,r=nums.size()-1,c;
        while(l<=r){
            c=(l+r)>>1;
            if(t>=nums[c][0]&&t<=nums[c][1]) return c;
            else if(t<nums[c][0]) r=c-1;
            else l=c+1;
        }
        return l;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int a=jgo(intervals, newInterval[0]), b=jgo(intervals, newInterval[1]),i,j;
        for(i=0;i<a;++i) ans.push_back(intervals[i]);
        if(a==intervals.size()) {
            ans.push_back(newInterval);
            return ans;
        }
        vector<int> t(2,0);
        if(newInterval[0]>=intervals[a][0]&&newInterval[0]<=intervals[a][1]){ // 命中区间
            if(b==intervals.size()){
                t[0]=intervals[a][0], t[1]=newInterval[1];
                ans.push_back(t);
            }else{
                if(newInterval[1]>=intervals[b][0]&&newInterval[1]<=intervals[b][1]){
                    t[0]=intervals[a][0], t[1]=intervals[b][1];
                    ans.push_back(t);
                    for(i=b+1;i<intervals.size();++i) ans.push_back(intervals[i]);
                }else{
                    t[0]=intervals[a][0], t[1]=newInterval[1];
                    ans.push_back(t);
                    for(i=b;i<intervals.size();++i) ans.push_back(intervals[i]);
                }
            }
        }else{ // 在区间之前
            if(b==intervals.size()){
                t[0]=newInterval[0], t[1]=newInterval[1];
                ans.push_back(t);
            }else{
                if(newInterval[1]>=intervals[b][0]&&newInterval[1]<=intervals[b][1]){
                    t[0]=newInterval[0], t[1]=intervals[b][1];
                    ans.push_back(t);
                    for(i=b+1;i<intervals.size();++i) ans.push_back(intervals[i]);
                }else{
                    t[0]=newInterval[0], t[1]=newInterval[1];
                    ans.push_back(t);
                    for(i=b;i<intervals.size();++i) ans.push_back(intervals[i]);
                }
            }
        }
        return ans;
    }
};