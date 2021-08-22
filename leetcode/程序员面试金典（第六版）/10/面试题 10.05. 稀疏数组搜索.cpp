// https://leetcode-cn.com/problems/sparse-array-search-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findString(vector<string>& words, string s) {
      int left=0, right=words.size()-1, mid,a,b;
      while(left<=right){
        mid=left+(right-left)/2;
        if(words[mid]==""){
          a=mid-1,b=mid+1;
          while(true){
            if(a<left&&b>right) return -1;
            else if(a>=left&&words[a]!="") {mid=a; break;}
            else if(b<=right&&words[b]!="") {mid=b; break;}
            else --a, ++b;
          }
        }
        if(words[mid]==s) return mid;
        else if(words[mid]<s) left=mid+1;
        else right=mid-1;
      }
      return -1;
    }
};