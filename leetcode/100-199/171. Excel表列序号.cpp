// https://leetcode-cn.com/problems/excel-sheet-column-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int i, n=columnTitle.size(), ans=0;
        for(i=0;i<n;++i){
            ans*=26;
            ans+=columnTitle[i]-'A'+1;
        }
        return ans;
    }
};
