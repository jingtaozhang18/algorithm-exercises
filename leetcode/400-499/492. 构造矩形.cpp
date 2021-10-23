// https://leetcode-cn.com/problems/construct-the-rectangle/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> constructRectangle(int area) {
    int x = sqrt(1.0 * area);
    while (area % x) --x;
    return { area / x, x };
  }
};