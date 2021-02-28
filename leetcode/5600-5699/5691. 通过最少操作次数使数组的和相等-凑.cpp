// https://leetcode-cn.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size(), i, j, ans=0, sum1=0, sum2=0, diff;
        if(6*min(m,n)<max(m,n)) return -1; // 无法实现
        vector<int> arr(m+n);
        
        for(auto e:nums1) sum1+=e;
        for(auto e:nums2) sum2+=e;

        if(sum1==sum2) return 0;
        else if(sum1>sum2){
          for(i=0,j=0;i<m;++i,++j) arr[j]=nums1[i]-1;
          for(i=0;i<n;++i,++j) arr[j]=6-nums2[i];
          sort(arr.rbegin(), arr.rend());
          i=0, diff=sum1-sum2;
          while(diff>0){
            diff-=arr[i++];
            ++ans;
          }
        }else {
          for(i=0,j=0;i<m;++i,++j) arr[j]=6-nums1[i];
          for(i=0;i<n;++i,++j) arr[j]=nums2[i]-1;
          sort(arr.rbegin(), arr.rend());
          i=0, diff=sum2-sum1;
          while(diff>0){
            diff-=arr[i++];
            ++ans;
          }
        }
        return ans;
    }
};