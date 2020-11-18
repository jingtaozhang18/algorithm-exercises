// https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        set<int> dump;
        int i,a;
        for(i=0;i<nums.size();++i){
            a=nums[i]; // i上面放置i+1的元素
            while(nums[i]!=i+1&&dump.find(nums[i])==dump.end()){
                // 把a放到a-1的位置上
                if(nums[a-1]==a){dump.insert(a); break;}
                nums[i]=nums[a-1], nums[a-1]=a, a=nums[i];;
            }
        }
        vector<int> ans;
        for(auto p:dump){
            ans.push_back(p);
        }
        return ans;
    }
};