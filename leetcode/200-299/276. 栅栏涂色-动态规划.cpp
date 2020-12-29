// https://leetcode-cn.com/problems/paint-fence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
      if(n==0||k==0) return 0;
      int same=0,diff=k,i,ns,nd;
      for(i=1;i<n;++i){
        ns=diff, nd=(k-1)*(same+diff);
        same=ns, diff=nd;
      }
      return same+diff;
    }
};