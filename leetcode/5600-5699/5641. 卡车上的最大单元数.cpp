// https://leetcode-cn.com/problems/maximum-units-on-a-truck/
#include<bits/stdc++.h>
using namespace std;

bool cmp(const vector<int>& a, const vector<int> b){
  return a[1]>b[1];
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(), boxTypes.end(), cmp);
      int i, ans=0, num;
      for(i=0;i<boxTypes.size()&&truckSize;++i)
      {
        num=min(truckSize, boxTypes[i][0]);
        truckSize-=num;
        ans+=num*boxTypes[i][1];
      }
      return ans;
    }
};