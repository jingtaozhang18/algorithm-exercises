// https://leetcode-cn.com/problems/n-queens/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> memC;
    vector<bool> memL; // 上面行,右斜线向下对当前行的影响
    vector<bool> memR; // 上面行,左斜线向下对当前行的影响
    vector<string> path;

    void jgo(int index, int n,  vector<vector<string>>& ans){
      int i,j;
      if(index==n) {ans.push_back(path); return;}
      for(i=0;i<n;++i){
        if(!memL[i]&&!memC[i]&&!memR[i]){
          path[index][i]='Q';
          memC[i]=true;
          vector<bool> tl(memL); vector<bool> tr(memR);
          memL[i]=true, memR[i]=true;
          for(j=n-1;j>0;--j) memL[j]=memL[j-1]; memL[j]=false;
          for(j=0;j<n-1;++j) memR[j]=memR[j+1]; memR[j]=false;
          jgo(index+1, n, ans);
          path[index][i]='.';
          memC[i]=false; memL=tl; memR=tr;
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      int i;
      memC.resize(n); for(i=0;i<n;++i) memC[i]=false;
      memL.resize(n); for(i=0;i<n;++i) memL[i]=false;
      memR.resize(n); for(i=0;i<n;++i) memR[i]=false;
      path.resize(n); for(i=0;i<n;++i) path[i]=string(n, '.');
      jgo(0,n,ans);
      return ans;
    }
};