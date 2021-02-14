// https://leetcode-cn.com/contest/weekly-contest-228/problems/minimum-limit-of-balls-in-a-bag/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(vector<int>& nums, int limit, int maxOperations){
        int t=0, f;
        for(auto e:nums){
            f=e/limit;
            if(e%limit) f++;
            maxOperations-=(f-1);
            if(maxOperations<0) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left, right=0, mid, size=nums.size();
        bool flag;
        long long acc=0;
        for(auto e:nums) acc+=e, right=max(right, e);
        left=acc/(size+2*maxOperations);
        left=max(left, 1);
        // cout<<left<<endl;
        while(left<=right){
            mid=left+(right-left)/2;
            flag=jgo(nums, mid, maxOperations);
            if(flag) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
};