// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jcalc(int x){
        int ans=0;
        while(x) ans+=x%10, x/=10;
        return ans;
    }
    void jgo(int m, int n, vector<vector<bool> >& mem, vector<vector<int> >& dir, int i, int j, int limit){
        int ii,jj;
        mem[i][j]=true;
        for(int k=0;k<dir.size();++k){
            ii=i+dir[k][0], jj=j+dir[k][1];
            if(!(ii>=0&&ii<m)) continue;
            if(!(jj>=0&&jj<n)) continue;
            if(mem[ii][jj]) continue;
            if(jcalc(ii)+jcalc(jj)<=limit)
                jgo(m, n, mem, dir, ii, jj, limit);
        }
    }
    int movingCount(int m, int n, int k) {
        vector<vector<int> > dir(4, vector<int>(2,0));
        dir[0][0]=-1,dir[0][1]=0;
        dir[1][0]=1,dir[1][1]=0;
        dir[2][0]=0,dir[2][1]=-1;
        dir[3][0]=0,dir[3][1]=1;
        vector<vector<bool> > mem(m, vector(n, false));
        jgo(m,n,mem,dir,0,0,k);
        int ans=0;
        for(int i=0;i<m;++i) for(int j=0;j<n;++j) ans+=mem[i][j]?1:0;
        return ans;
    }
};