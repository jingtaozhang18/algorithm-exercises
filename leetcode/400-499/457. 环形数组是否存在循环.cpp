// https://leetcode-cn.com/problems/circular-array-loop/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int label=2000, i, j, m=nums.size(), x;
        bool positive, valid;
        for(i=0;i<m;++i){
            if(nums[i]<2000){ // 没有出发过 
                positive=nums[i]>0;
                j=i;
                valid=true;
                while(nums[j]!=label&&nums[j]>0==positive&&nums[j]<2000){
                    x=nums[j];
                    x+=(1000/m+1)*m;
                    nums[j]=label;
                    if(j==(j+x)%m) valid=false;
                    j=(j+x)%m;
                }
                if(nums[j]==label&&valid) return true;
                ++label;
            }
        }
        return false;
    }
};
