// https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i, m=arr.size();
        for(i=1;i<m-1;++i){
            if(arr[i-1]<arr[i]&&arr[i]>arr[i+1]) return i;
        }
        return -1;
    }
};
