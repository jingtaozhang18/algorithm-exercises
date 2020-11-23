// https://leetcode-cn.com/problems/put-boxes-into-the-warehouse-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        vector<int> l(warehouse);
        vector<int> r(warehouse);
        int i,j,n=warehouse.size(),m=boxes.size(),ans=0;
        for(i=1;i<n;++i) l[i]=min(l[i], l[i-1]);
        for(i=n-2;i>=0;--i) r[i]=min(r[i], r[i+1]);
        for(i=0;i<n;++i) warehouse[i]=max(l[i], r[i]);
        sort(warehouse.begin(), warehouse.end());
        sort(boxes.begin(), boxes.end());
        for(j=0,i=0;i<m;){
            while(j<n&&warehouse[j]<boxes[i])j++;
            if(j<n) ans++,++i,++j;
            else break;
        }
        return ans;
    }
};