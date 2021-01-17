// https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double d;
        bool constx=false;
        // 错误点 需要转浮点数
        int i;double x1=coordinates[0][0], y1=coordinates[0][1], x2=coordinates[1][0], y2=coordinates[1][1];
        if(x1==x2) constx=true; else d=(y2-y1)/(x2-x1);
        for(i=2;i<coordinates.size();++i){
            x1=coordinates[i-1][0], y1=coordinates[i-1][1], x2=coordinates[i][0], y2=coordinates[i][1];
            if(constx) {if(x1!=x2) return false;}
            else {
                if(x2==x1||abs((y2-y1)/(x2-x1)-d)>0.00000000001) return false;
            }
        }
        return true;
    }
};