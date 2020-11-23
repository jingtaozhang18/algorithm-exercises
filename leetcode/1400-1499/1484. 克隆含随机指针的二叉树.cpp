// https://leetcode-cn.com/problems/clone-binary-tree-with-random-pointer/
#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int val;
    Node *left;
    Node *right;
    Node *random;
    Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
};
struct NodeCopy {
    int val;
    NodeCopy *left;
    NodeCopy *right;
    NodeCopy *random;
    NodeCopy() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
    NodeCopy(int x, NodeCopy *left, NodeCopy *right, NodeCopy *random) : val(x), left(left), right(right), random(random) {}
};
class Solution {
public:
    NodeCopy* jgo(Node* root, map<Node*, NodeCopy*>& mp){
        if(!root) return nullptr;
        NodeCopy *nr = new NodeCopy(root->val);
        mp[root]=nr;
        nr->left=jgo(root->left, mp);
        nr->right=jgo(root->right, mp);
        return nr;
    }
    void jcr(Node*old_root, NodeCopy*new_root, map<Node*, NodeCopy*>& mp){
        if(!old_root) return;
        new_root->random=mp[old_root->random];
        jcr(old_root->left, new_root->left, mp);
        jcr(old_root->right, new_root->right, mp);
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        map<Node*, NodeCopy*> mp;
        NodeCopy *ans=jgo(root, mp); // 获取拷贝
        jcr(root, ans, mp);
        return ans;
    }
};