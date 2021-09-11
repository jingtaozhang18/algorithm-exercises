// https://leetcode-cn.com/problems/Ygoe9J/
#include<bits/stdc++.h>
using namespace std;

// 有误
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int total_num = 0;
    void calc(int i, vector<tuple<int,int,int>> from[]){
        if(i==0) {
            if(path.size()&&ans.size()<total_num){
                ans.push_back(path);
            }
            return;
        };
        int j;
        for(auto &e:from[i]){
            auto [pre_i, ele, times] = e;
            if(path.size()&&path.back()<ele) continue;
            path.push_back(ele);
            for(j=0;j<times;++j){
                calc(pre_i, from);
            }
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int arr[target+1];
        vector<tuple<int,int,int>> from[target+1]; // from
        int i, j=0;
        for(i=1;i<=target;++i) arr[i]=0;
        arr[0]=1;
        sort(candidates.begin(), candidates.end());
        for(auto& e:candidates){
            for(i=0;i+e<=target;++i){
                if(arr[i]){
                    arr[i+e]+=arr[i];
                    from[i+e].emplace_back(i, e, arr[i]);
                }
            }
            ++j;
        }
        total_num = arr[target];
        calc(target, from);
        return ans;
    }
};