// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
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
    void jgo(Node*a, Node*b){
      a->next=b;
      if(a->left){
        jgo(a->left, a->right);
        jgo(a->right, b->left);
        jgo(b->left, b->right);
      }
    }
    Node* connect(Node* root) {
        if(root&&root->left) jgo(root->left, root->right);
        return root;
    }
};