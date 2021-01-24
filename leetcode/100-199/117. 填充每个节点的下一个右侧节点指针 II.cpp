// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
      Node *tr=root, *a, *ntr;
      while(tr){
        a=nullptr, ntr=nullptr;
        while(tr){
          if(tr->left){
            if(!a) {a=tr->left; if(!ntr) ntr=a;}
            else a->next=tr->left, a=a->next;
          }
          if(tr->right){
            if(!a) {a=tr->right; if(!ntr) ntr=a;}
            else a->next=tr->right, a=a->next;
          }
          tr=tr->next;
        }
        tr=ntr;
      }
      return root;
    }
};