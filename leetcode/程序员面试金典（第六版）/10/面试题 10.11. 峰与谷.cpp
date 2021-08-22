// https://leetcode-cn.com/problems/peaks-and-valleys-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
      sort(nums.begin(), nums.end(), greater<int>());
      vector<int> t(nums);
      int i=0,j=nums.size()-1,k=0;
      bool flag=true;
      while(i<=j) nums[k++]=flag?t[i++]:t[j--], flag=!flag;
    }
};