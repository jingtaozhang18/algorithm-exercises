// https://leetcode-cn.com/problems/one-away-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(string &first, string &second, int i, int j){
      if(i==first.size()) return second.size()-j;
      if(j==second.size()) return first.size()-i;
      if(first[i]==second[j]) return jgo(first, second, i+1, j+1);
      return min({jgo(first, second, i, j+1), jgo(first, second, i+1, j+1), jgo(first, second, i+1, j)})+1;
    }
    bool oneEditAway(string first, string second) {
      return jgo(first, second, 0, 0)<=1;
    }
};