// https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array/
#include<bits/stdc++.h>
using namespace std;

struct node{
  node *left, *right;
  node():left(nullptr),right(nullptr){}
};
class Solution {
public:
    node *root;
    int fn=0x80000000;
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
            if(!t->right) t->right=new node();
            t=t->right;
          }else
          {
            if(!t->left) t->left=new node();
            t=t->left;
          }
        }
      }
    }
    int jfind(int m, int x, int ans, bool flag, node* t, int level){
      int tmp;
      if(level==fl) return ans;
      int mm=(unsigned int)m<<1, xx=(unsigned int)x<<1;
      if(!flag) // 需要保持小于关系
      {
        if(m&fn) // 都可走
        {
          if(!(x&fn)) // 推荐向右走
          {
            if(t->right)
            {
              tmp=jfind(mm, xx, (ans<<1)+1, false, t->right, level+1);
              if(tmp==-1&&t->left) return jfind(mm, xx, (ans<<1), true, t->left, level+1);
              else return tmp;
            }
            else return jfind(mm, xx, (ans<<1), true, t->left, level+1);
          }
          else // 推荐向左
          {
            if(t->left) return jfind(mm, xx, (ans<<1), true, t->left, level+1); // 向左
            else return jfind(mm, xx, (ans<<1)+1, false, t->right, level+1); // 向右
          }
        }
        else
        { // 受限于大小，只能向左
            if(t->left) return jfind(mm, xx, (ans<<1), false, t->left, level+1);
            else return -1;
        }
      }else
      {
        if(!(x&fn)){ // 推荐向右走
            if(t->right)
            {
              tmp=jfind(mm, xx, (ans<<1)+1, true, t->right, level+1);
              if(tmp==-1&&t->left) return jfind(mm, xx, (ans<<1), true, t->left, level+1);
              else return tmp;
            }
            else return jfind(mm, xx, (ans<<1), true, t->left, level+1);
        }else 
        {
         if(t->left) return jfind(mm, xx, (ans<<1), true, t->left, level+1); // 向左
         else return jfind(mm, xx, (ans<<1)+1, true, t->right, level+1); // 向右
        }
      }
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
      jbuild(nums);
      int i,size=queries.size();
      vector<int> ans(size);
      for(i=0;i<size;++i) {ans[i]=jfind(queries[i][1], queries[i][0], 0, false, root, 0);if(ans[i]!=-1)ans[i]^=queries[i][0];}
      return ans;
    }
};