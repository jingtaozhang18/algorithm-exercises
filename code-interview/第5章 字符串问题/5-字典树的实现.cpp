#include<bits/stdc++.h>
using namespace std;

struct node{
  int num;
  int pre_num;
  struct node* next[26];
  node():num(0),pre_num(1){memset(next,0,sizeof next);}
};

class Tree{
public:
  node* head;
  Tree():head(new node()){};
  void insert(string& s){
    node* t = head;
    for(char c:s){
      if(t->next[c-'a']){ // 节点本身就存在
        t->next[c-'a']->pre_num++;
      }else{
        t->next[c-'a']=new node();
      }
      t=t->next[c-'a'];
    }
    t->num++;
  }
  void del(string& s){ // 保证节点肯定存在
    node* t = head;
    for(char c:s){
      t=t->next[c-'a'];
      t->pre_num--;
    }
    t->num--;
  }
  bool has(string& s){
    node* t = head;
    for(char c:s){
      if(!t) return false;
      t=t->next[c-'a'];
    }
    return t&&t->num>0?true:false;
  }
  int pre_size(string &s){
    node* t = head;
    for(char c:s){
      if(!t) return 0;
      t=t->next[c-'a'];
    }
    return t?t->pre_num:0;
  }

};

int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, op;
  string s;
  Tree tree;
  cin>>n;
  while(n--){
    cin>>op>>s;
    if(op==1){
      tree.insert(s);
    }else if(op==2){
      tree.del(s);
    }else if(op==3){
      cout<<(tree.has(s)?"YES":"NO")<<endl;
    }else{
      cout<<tree.pre_size(s)<<endl;
    }
  }
  return 0;
}