// https://leetcode-cn.com/problems/NaqhDT/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class CBTInserter {
 public:
  queue<TreeNode *> que;
  TreeNode *root;
  CBTInserter(TreeNode *root) {
    this->root = root;
    que.push(root);
    while (que.front()->left) {
      que.push(que.front()->left);
      if (que.front()->right) {
        que.push(que.front()->right);
        que.pop();
      } else {
        break;
      }
    }
  }

  int insert(int v) {
    TreeNode *node = new TreeNode(v);
    TreeNode *f = que.front();
    if (!f->left) {
      f->left = node;
    } else {
      f->right = node;
      que.pop();
    }
    que.push(node);
    return f->val;
  }

  TreeNode *get_root() { return root; }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */