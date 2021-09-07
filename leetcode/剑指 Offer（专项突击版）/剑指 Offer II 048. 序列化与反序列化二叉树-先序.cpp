// https://leetcode-cn.com/problems/h54YBf/
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {  // 先序遍历
    if (!root) return "";
    stack<TreeNode*> sta;
    sta.push(root);
    string ans;
    while (sta.size()) {
      root = sta.top();
      sta.pop();
      if (root)
        ans += to_string(root->val) + ",";
      else
        ans += "#,";
      if (root) {
        sta.push(root->right);
        sta.push(root->left);
      }
    }
    cout << ans << endl;
    return ans;
  }
  int calc(string& str, int& i) {
    int ans = 0;
    bool flag = true;
    while (i < str.size() && str[i] != ',') {
      if (str[i] == '#')
        ans = INT_MAX;
      else if (str[i] == '-') {
        flag = false;
      } else {
        ans *= 10, ans += str[i] - '0';
      }
      ++i;
    }
    return flag ? ans : -ans;
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int i = 0, val;
    TreeNode *root = nullptr, *t;
    stack<TreeNode*> sta;
    bool flag = false;
    for (i = 0; i < data.size(); ++i) {
      val = calc(data, i);
      if (val != INT_MAX) {
        if (!root) {
          root = new TreeNode(val);
          sta.push(root);
        } else {
          t = new TreeNode(val);
          if (flag || sta.top()->left) {  // 右孩子
            sta.top()->right = t;
            sta.pop();
            sta.push(t);
            flag = false;
          } else {  // 左孩子
            sta.top()->left = t;
            sta.push(t);
          }
        }
      } else {
        if (!flag && !sta.top()->left)
          flag = true;
        else {
          flag = false;
          sta.pop();
        }
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));