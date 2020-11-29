// https://leetcode-cn.com/problems/video-stitching/
#include<bits/stdc++.h>
using namespace std;

// https://leetcode-cn.com/problems/video-stitching/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
      int i, size=clips.size(),base,ans,t,j,x;
      vector<int> mem(T+1, 0); // 从每个位置出发能达到的最远的位置
      for(auto av:clips){ if(av[0]<=T) mem[av[0]]=max(mem[av[0]], av[1]); }
      if(!mem[0]) return -1;
      t=-1, base=ans=0;
      while(base<T){
        for(j=base,x=-1;j>t;--j) x=max(x, mem[j]);
        if(x>base) t=base, base=x, ans++;
        else return -1;
      }
      return ans;
    }
};