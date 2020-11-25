// https://leetcode-cn.com/problems/UlBDOe/
#include<bits/stdc++.h>
using namespace std;

// 暴力超时
class Solution {
public:
    int minimumOperations(string leaves) {
        int size=leaves.size(),i,j,ans=size;
        vector<int> r(size+1,0);
        vector<int> y(size+1,0);
        for(i=0;i<size;++i) 
            r[i+1]=r[i]+((leaves[i]=='r')?1:0), y[i+1]=y[i]+((leaves[i]=='y')?1:0);
        // for(i=0;i<=size;++i) cout<<r[i]<<" "; cout<<endl;
        // for(i=0;i<=size;++i) cout<<y[i]<<" "; cout<<endl;
        for(i=1;i<size-1;++i){
            for(j=i+1;j<size;++j){
                ans=min(ans, y[i]+r[j]-r[i]+y[size]-y[j]);
                // cout<<i<<" "<<j<<": "<<ans<<endl;
            }
        }
        return ans;
    }
};