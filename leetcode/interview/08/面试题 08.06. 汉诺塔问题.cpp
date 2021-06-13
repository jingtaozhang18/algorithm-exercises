// https://leetcode-cn.com/problems/hanota-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 将A上index个盘子借助B移动到C
    void jgo(vector<int>& A, vector<int>& B, vector<int>& C, int index) {
        if(index==0) return;
        else if(index==1) {
            C.push_back(A.back()); A.pop_back();
        }else if(index==2) {
            B.push_back(A.back()); A.pop_back(); 
            C.push_back(A.back()); A.pop_back();
            C.push_back(B.back()); B.pop_back();
        }else{
            jgo(A, C, B, index-1);
            C.push_back(A.back()); A.pop_back();
            jgo(B, A, C, index-1);
        }
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        jgo(A, B, C, A.size());
    }
};