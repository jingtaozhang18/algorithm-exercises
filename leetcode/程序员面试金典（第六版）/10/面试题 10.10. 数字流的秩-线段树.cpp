// https://leetcode-cn.com/problems/rank-from-stream-lcci/
#include<bits/stdc++.h>
using namespace std;

struct node{
  int left, right, num;
  node *l, *r;
  node(int left, int right, int num):left(left),right(right),num(num),l(nullptr),r(nullptr){}
};

class StreamRank {
public:
    node *root;
    StreamRank() {
      root=new node(INT_MIN, 50000, 0);
    }
    
    void track(int x) {
      node *t=root;
      root->num++;
      while(t->left!=t->right)
      {
        int centr=(t->left+t->right)/2;
        if(x<=centr)
        {
          if(!t->l) t->l=new node(t->left, centr, 0);
          t=t->l;
          t->num++;
        }else
        {
          if(!t->r) t->r=new node(centr+1, t->right, 0);
          t=t->r;
          t->num++;
        }
      }
    }
    
    int jfind(node* root, int x){
      if(!root) return 0;
      if(root->right<=x) return root->num;
      return jfind(root->l, x)+jfind(root->r, x);
    }
    int getRankOfNumber(int x) {
      return jfind(root, x);
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */