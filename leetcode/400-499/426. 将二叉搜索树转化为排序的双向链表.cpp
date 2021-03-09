// https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        stack<Node*> sta;
        Node* cur=root, *head=nullptr, *pre=nullptr;
        while(cur||sta.size()){
            while(cur) {sta.push(cur);cur=cur->left;}
            cur=sta.top(); sta.pop();
            if(!head) head=cur;
            else pre->right=cur, cur->left=pre;
            pre = cur;
            cur = cur->right;
        }
        pre->right=head, head->left=pre;
        return head;
    }
};