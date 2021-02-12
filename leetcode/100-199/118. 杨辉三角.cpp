// https://leetcode-cn.com/problems/pascals-triangle/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        int index, i, a, b;
        for(index=0;index<numRows;++index){
            ans.push_back(vector<int>(index+1, 1));
            if(index){
                for(i=0;i<index;++i){
                    if(i==0) a=0;
                    else a=ans[index-1][i-1];
                    if(i==index) b=0;
                    else b=ans[index-1][i];
                    ans[index][i]=a+b;
                }
            }
        }
        return ans;
    }
};