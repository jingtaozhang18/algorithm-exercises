// https://leetcode-cn.com/problems/combination-sum-iv/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calc(int m, int n){ // 从m个总数中，取出n个位置
        int ans=1, i=1;
        for(i=1;i<=n;++i) ans*=m, ans/=i, --m; // 溢出; 暂时没有比较好的解决办法
        return ans;
    }
    int jgo(vector<int>& nums, int index, int target, vector<int>& path){
        int ans=0, acc=1, sum=0, j;
        if(index==nums.size()&&target==0){
            // 计算排序数量
            for(auto &e:path) sum+=e;
            for(auto &e:path) acc*=calc(sum, e), sum-=e;
            return acc;
        }
        if(index==nums.size()) return 0;
        for(j=0;target-nums[index]*j>=0;++j){
            path.push_back(j);
            ans+=jgo(nums, index+1, target-nums[index]*j, path);
            path.pop_back();
        }
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> path;
        return jgo(nums, 0, target, path);
    }
};