// https://leetcode-cn.com/problems/4xy4Wx/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calc(vector<int> &nums, int tar){ // 大于等于tar的第一个元素
        int left=0, right=nums.size()-1, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]<=tar){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return left;
    }
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long i, ans=0, m=1000000007*2;
        for(i=0;i<nums.size();++i){
            int mid=calc(nums, target-nums[i]);
            if(mid>i) ans+=mid-1;
            else ans+=mid;
            ans%=m;
        }
        return ans/2;
        // if(ans<=1000000007) return ans;
        // else return ans-1000000007;
    }
};