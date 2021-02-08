// https://leetcode-cn.com/problems/longest-turbulent-subarray/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size=arr.size(), left=0, right=0, ans=1;
        bool flag;
        while(right<size){
            while(left+1<size&&arr[left]==arr[left+1]) left++; // 找到满意的起点
            right=left+1;
            if(right==size) break;
            flag=arr[right]<arr[left]; // 奠定基调
            while(right<size&&arr[right]!=arr[right-1]&&((arr[right]>arr[right-1]) ^ flag)) right++, flag=!flag;
            ans=max(ans, right-left);
            left=right-1;
        }
        return ans;
    }
};