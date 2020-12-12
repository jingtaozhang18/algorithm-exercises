// https://leetcode-cn.com/problems/increasing-subsequences/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int i,j,size=nums.size(),t;
        vector<vector<int>> ans, res;
        vector<int> tarr;
        if(!size) return ans;
        for(i=0;i<size;++i){
            t=res.size();
            for(j=0;j<t;++j){
                if(nums[i]>=res[j][res[j].size()-1]){
                    tarr=res[j]; tarr.push_back(nums[i]);
                    res.push_back(tarr);
                }
            }
            tarr={nums[i]};
            res.push_back(tarr);
        }
        set<vector<int>> st;
        for(i=0;i<res.size();++i){
            if(res[i].size()>1&&st.find(res[i])==st.end()){
                ans.push_back(res[i]); 
                st.insert(res[i]);
            }
        }
        return ans;
    }
};