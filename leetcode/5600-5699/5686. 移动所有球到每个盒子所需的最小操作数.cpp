// https://leetcode-cn.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int size=boxes.size(), i, j;
        vector<int> ans(size);
        for(i=0;i<size;++i){
            for(j=0;j<size;++j){
                if(boxes[j]=='1') ans[i]+=abs(j-i);
            }
        }
        return ans;
    }
};