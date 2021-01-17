// https://leetcode-cn.com/contest/weekly-contest-224/problems/number-of-rectangles-that-can-form-the-largest-square/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int ans=0, maxL=0,t;
        for(auto e:rectangles){
            t=min(e[0],e[1]);
            if(t<maxL) continue;
            else if(t==maxL) ans++;
            else{
                ans=1, maxL=t;
            }
        }
        return ans;
    }
};