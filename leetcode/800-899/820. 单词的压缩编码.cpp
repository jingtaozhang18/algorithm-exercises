// https://leetcode-cn.com/problems/short-encoding-of-words/
#include<bits/stdc++.h>
using namespace std;

struct node{
  node* child[26];
  node(){memset(child,0,sizeof(child));}
};

void jbuild(node*root, string&s){
  int i,t,n=s.size();
  for(i=n-1;i>=0;--i){
    t=s[i]-'a';
    if(root->child[t]) root=root->child[t];
    else root->child[t]=new node(), root=root->child[t];
  }
}

int jcalc(node* root, int& level){
    int ans=0;
    bool flag=false;
    level++;
    for(int i=0;i<26;++i) 
      if(root->child[i]) 
        ans+=jcalc(root->child[i], level), flag=true;
    if(!flag) ans+=level; // 叶子结点
    level--;
    return ans;
}

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
      node* root=new node();
      int i,ans=0,level=0;
      for(i=0;i<words.size();++i) jbuild(root, words[i]);
      ans=jcalc(root, level);
      return ans;
    }
};