// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
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
    Node* jgo(Node* root, Node* father){ // 返回最左侧孩子
        Node *a=0, *b=0, *next=0, *re=0; // 树的最左侧分支
        if(root->left) re=jgo(root->left, root);
        else re=root;
        if(root->right) b=jgo(root->right, father);
        if(b) next=b;
        else next=father;
        root->right=next;
        if(next) next->left=root;
        return re;
    }
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node *head=jgo(root, nullptr);
        Node *t=head;
        while(t->right)t=t->right;
        t->right=head,head->left=t;
        return head;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        stack<Node*> sta;
        Node* cur=root, *head=nullptr, *pre=nullptr;
        while(cur||sta.size()){ // 非递归的中序遍历
            while(cur) {sta.push(cur);cur=cur->left;} // 中序框架
            cur=sta.top(); sta.pop(); // 中序框架
            if(!head) head=cur;
            else pre->right=cur, cur->left=pre;
            pre = cur;
            cur = cur->right; // 中序框架
        }
        pre->right=head, head->left=pre;
        return head;
    }
};