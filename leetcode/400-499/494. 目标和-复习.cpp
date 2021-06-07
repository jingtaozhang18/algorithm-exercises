// https://leetcode-cn.com/problems/target-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> cur, next;
        int i, n=nums.size();
        cur[0]=1;
        for(i=0;i<n;++i){
            for(auto p=cur.begin();p!=cur.end();++p){
                next[p->first+nums[i]]+=p->second;
                next[p->first-nums[i]]+=p->second;
            }
            cur=move(next);
            next=unordered_map<int, int>();
        }
        return cur[target];
    }
};