// https://leetcode-cn.com/problems/pascals-triangle-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans[0]=1;
        int index;
        for(index=1;index<=rowIndex;++index){
            ans[index]=1ll*ans[index-1]*(rowIndex-index+1)/index;
        }
        return ans;
    }
};