// https://leetcode-cn.com/problems/permutations/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int i,j,x,size=nums.size();
        vector<vector<int>> ans;
        stack<int> sta;
        while(true){
            if(sta.size()==nums.size()) {
                ans.push_back(nums);
                j=size; // 确保可以进入循环
                while(j==size&&!sta.empty()){
                    j=sta.top(); sta.pop();
                    // swap i,j 交换回来
                    i=sta.size();
                    x=nums[i], nums[i]=nums[j], nums[j]=x;
                    j++;
                }
                if(j==size) break;
                i=sta.size();
                sta.push(j);
                // swap i,j
                x=nums[i], nums[i]=nums[j], nums[j]=x;
            }else{
                sta.push(sta.size());
            }
        }
        return ans;
    }
};