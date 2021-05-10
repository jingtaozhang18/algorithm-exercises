// https://leetcode-cn.com/problems/n-queens-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int> row;
    unordered_set<int> col;
    unordered_set<int> right;
    unordered_set<int> left;
    int ans=0;
    void jgo(int index, int n){
        if(index==n) {
            ++ans;
            return;
        }
        int i=index;
        if(row.find(i)!=row.end()) return;
        for(int j=0;j<n;++j){
            if(col.find(j)!=col.end()) continue;
            if(right.find(i-j)!=right.end()) continue;
            if(left.find(j+i)!=left.end()) continue;
            // cout<<"add: "<<i<<" "<<j<<endl;
            row.insert(i), col.insert(j), right.insert(i-j), left.insert(j+i);
            jgo(index+1, n);
            // cout<<"remove: "<<i<<" "<<j<<endl;
            row.erase(i), col.erase(j), right.erase(i-j), left.erase(j+i);
        }
    }
    int totalNQueens(int n) {
        jgo(0, n);
        return ans;
    }
};