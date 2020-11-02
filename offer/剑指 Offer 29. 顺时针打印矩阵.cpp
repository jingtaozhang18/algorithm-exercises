// https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size()==0||matrix[0].size()==0) return ans;
        int a=0,b=0,c=matrix.size()-1,d=matrix[0].size()-1,i,j;// (a, b)左上角， (c, d)右下角
        while(a<=c&&b<=d){
            i=a,j=b;
            ans.push_back(matrix[i][j]);
            if(b!=d) {for(++j;j<=d;++j) ans.push_back(matrix[i][j]); j--;}
            if(a!=c) {for(++i;i<=c;++i) ans.push_back(matrix[i][j]); i--;}
            if(a!=c) {for(--j;j>=b;--j) ans.push_back(matrix[i][j]); ++j;}
            if(b!=d) {for(--i;i>a;--i) ans.push_back(matrix[i][j]); ++i;}
            a++,b++,c--,d--;
        }
        return ans;
    }
};