// https://leetcode-cn.com/problems/zigzag-conversion/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<vector<char>> mem(numRows, vector<char>());
        int i,j=2*numRows-2,k;
        for(i=0;i<s.size();++i){
            k=i%j; // 组内编号
            if(k>=numRows) k=numRows-2-k%numRows;
            mem[k].push_back(s[i]);
        }
        string ans="";
        for(i=0;i<numRows;++i){
            for(j=0;j<mem[i].size();++j){
                ans+=mem[i][j];
            }
        }
        return ans;
    }
};