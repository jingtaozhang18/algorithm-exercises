// https://leetcode-cn.com/problems/merge-sorted-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k=m+n;
        --m, --n, --k;
        while(m>=0&&n>=0){
            if(nums1[m]>nums2[n]) nums1[k--]=nums1[m--];
            else nums1[k--]=nums2[n--];
        }
        while(n>=0) nums1[k--]=nums2[n--];
    }
};