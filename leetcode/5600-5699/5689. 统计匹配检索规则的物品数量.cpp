// https://leetcode-cn.com/problems/count-items-matching-a-rule/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans=0, i, j, index, size=items.size();
        if(ruleKey=="type") index=0;
        else if(ruleKey=="color") index=1;
        else index=2;
        for(i=0;i<size;++i){
            if(items[i][index]==ruleValue) ++ans;
        }
        return ans;
    }
};