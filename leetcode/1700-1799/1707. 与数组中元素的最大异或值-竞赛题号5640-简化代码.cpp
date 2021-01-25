// https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/
#include<bits/stdc++.h>
using namespace std;

struct node{
  node *next[2];
  node(){next[0]=next[1]=nullptr;}
};
class Solution {
public:
    node *root;
    unsigned int fn=0x80000000;
    int fl=32;
    void jbuild(vector<int>& nums){
      root=new node();
      node *t; int i;
      for(int a:nums){
        t=root;
        for(i=0;i<fl;++i,a=(unsigned int)a << 1)
        {
          if(a&fn)
          {
            if(!t->next[1]) t->next[1]=new node();
            t=t->next[1];
          }else
          {
            if(!t->next[0]) t->next[0]=new node();
            t=t->next[0];
          }
        }
      }
    }
    int jfind(int m, int x, int ans, bool flag, node* t, int level){
      // 不超过m和x异或的最大结果
      if(level==fl) return ans;
      bool mf=m&(fn>>level); // m第level位置的状态
      bool xf=x&(fn>>level); // x第level位置的状态
      int tj=!xf; // 推荐位置
      int tmp=-1;
      for(int i=0;i<2;++i,tj=1-tj){
        if(t->next[tj]&&(mf||!flag||!tj)) tmp=jfind(m,x,(ans<<1)+tj, flag&((!mf&!tj)|(mf&tj)), t->next[tj], level+1);
        if(tmp!=-1) return tmp;
      }
      return tmp;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
      jbuild(nums);
      int i,size=queries.size();
      vector<int> ans(size);
      for(i=0;i<size;++i) {
        ans[i]=jfind(queries[i][1], queries[i][0], 0, true, root, 0);
        cout<<ans[i]<<endl;
        if(ans[i]!=-1)ans[i]^=queries[i][0];
      }
      return ans;
    }
};