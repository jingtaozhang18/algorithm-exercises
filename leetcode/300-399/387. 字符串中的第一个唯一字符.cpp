// https://leetcode-cn.com/problems/first-unique-character-in-a-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
      vector<int> arr(200, -1);
      int i=0;
      char c;
      for(i=0;i<s.size();++i){
        c=s[i];
        if(arr[c]==-1) arr[c]=i;
        else arr[c]=-2; 
      }
      int index=INT_MAX;
      for(i=0;i<200;++i){
        if(arr[i]>=0){
          index=min(index, arr[i]);
        }
      }
      return index==INT_MAX?-1:index; 
    }
};