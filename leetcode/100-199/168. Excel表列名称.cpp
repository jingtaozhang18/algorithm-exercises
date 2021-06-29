// https://leetcode-cn.com/problems/excel-sheet-column-title/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        stack<int> sta;
        long long base=26, ob=1, i;
        while(columnNumber){
            sta.push(columnNumber%base/ob);
            columnNumber-=(sta.top()==0?26:sta.top())*ob;
            ob=base, base *= 26;
        }
        string ans(sta.size(), ' ');
        i=0;
        while(sta.size()){
            if(sta.top()==0) ans[i]='Z';
            else ans[i]=sta.top()-1+'A';
            i++;
            sta.pop();
        }
        return ans;
    }
};
