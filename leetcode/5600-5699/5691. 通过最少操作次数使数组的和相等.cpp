// https://leetcode-cn.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>& arr, int target){
        int left=0, right=arr.size()-1, mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]>=target) right=mid-1;
            else left=mid+1;
        }
        return left;
    }
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size(), ans=m+n, t, k, sum1=0, sum2=0;
        if(m>n) swap(nums1, nums2), swap(m,n);
        // m<=n
        if(6*m<n) return -1; // 无法实现
        sort(nums1.begin(), nums1.end()); // 从小到大
        sort(nums2.begin(), nums2.end()); // 从小到大
        
        for(auto e:nums1) sum1+=e;
        for(auto e:nums2) sum2+=e;
        
        vector<int> des1(m+1);
        vector<int> des2(n+1);
        vector<int> inc1(m+1);
        vector<int> inc2(n+1);
        
        for(int i=1;i<=m;++i){
            des1[i]=(nums1[m-i]-1)+des1[i-1];
            inc1[i]=(6-nums1[i-1])+inc1[i-1];
        }
        for(int i=1;i<=n;++i){
            des2[i]=(nums2[n-i]-1)+des2[i-1];
            inc2[i]=(6-nums2[i-1])+inc2[i-1];
        }
        
        for(k=n;k<=6*m;++k){
            t=0;
            if(sum1>k){
                t+=jgo(des1, sum1-k);
            }else if(sum1<k){
                t+=jgo(inc1, k-sum1);
            }
            if(sum2>k){
                t+=jgo(des2, sum2-k);
            }else if(sum2<k){
                t+=jgo(inc2, k-sum2);
            }
            ans=min(ans, t);
        }
        return ans;
    }
};