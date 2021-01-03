// https://leetcode-cn.com/problems/lru-cache-lcci/
#include<bits/stdc++.h>
using namespace std;

struct node{
  int val;
  node *pre, *next;
  node():pre(nullptr),next(nullptr){};
  node(int val):val(val),pre(nullptr),next(nullptr){};
};
// 除了双向链表的操作，还需要理清map以及其他变量的操作
class LRUCache {
public:
    node *root;
    node *tail;
    int cap, size;
    map<int, node*> pos;
    map<int, int> mem;
    LRUCache(int capacity) {
      root=new node();
      tail=root;
      size=0, cap=capacity;
    }

    void jnew(node *nd){ // 将节点更新
      if(root->next==nd) return;
      if(nd->next)
      { // 不是尾节点
        nd->pre->next=nd->next;
        nd->next->pre=nd->pre;
      }else
      { // 是尾节点
        nd->pre->next=nullptr;
        tail=nd->pre;
      }
      root->next->pre=nd;
      nd->next=root->next;
      root->next=nd;
      nd->pre=root;
    }

    void jinset(node* nd){
      nd->next=root->next;
      if(root->next) root->next->pre=nd; // 不是第一个元素
      else tail=nd; // 第一个元素
      nd->pre=root;
      root->next=nd;
      ++size;
    }

    void jdelete(){
      // 删除尾元素
      node *t=tail;
      tail=tail->pre;
      tail->next=nullptr;
      mem.erase(mem.find(t->val));
      pos.erase(pos.find(t->val));
      --size;
      delete t;
    }

    int get(int key) {
      if(mem.find(key)==mem.end()) return -1;
      jnew(pos.find(key)->second);
      return mem[key];
    }
    
    void put(int key, int value) {
      if(mem.find(key)!=mem.end())
      {
        mem[key]=value;
        jnew(pos[key]);
        return;
      }
      if(size==cap) jdelete();
      node *nd=new node(key);
      mem[key]=value;
      pos[key]=nd;
      jinset(nd);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */