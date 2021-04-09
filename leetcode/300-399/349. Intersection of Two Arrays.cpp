// https://leetcode-cn.com/problems/intersection-of-two-arrays/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0, m=nums1.size(), n=nums2.size();
        vector<int> ans;
        while(i<m&&j<n){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                do{++i;}while(i<m&&nums1[i-1]==nums1[i]);
                do{++j;}while(j<n&&nums2[j-1]==nums2[j]);
            }else if(nums1[i]<nums2[j]){
                do{++i;}while(i<m&&nums1[i-1]==nums1[i]);
            }else{
                do{++j;}while(j<n&&nums2[j-1]==nums2[j]);
            }
        }
        return ans;
    }
};