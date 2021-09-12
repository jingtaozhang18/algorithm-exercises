// https://leetcode-cn.com/problems/ms70jA/
#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* childs[2];
  Node() {
    for (auto& child : childs) child = nullptr;
  }
};

class Solution {
 public:
  Node* root = new Node();
  void insert(unsigned int val) {
    Node* t = root;
    int i = 0, x;
    for (i = 0; i < 32; ++i) {
      x = (val & 0x80000000) ? 1 : 0;
      val <<= 1;
      if (!t->childs[x]) t->childs[x] = new Node();
      t = t->childs[x];
    }
  }
  int find(unsigned int val) {
    Node* t = root;
    int i = 0, x, ans = 0;
    // cout<<val<<"\t";
    for (i = 0; i < 32; ++i) {
      x = (val & 0x80000000) ? 1 : 0;
      x = 1 - x;
      val <<= 1, ans <<= 1;
      if (t->childs[x])
        t = t->childs[x], ans += x;
      else
        t = t->childs[1 - x], ans += (1 - x);
    }
    // cout<<ans<<"\t";
    return ans;
  }

  int findMaximumXOR(vector<int>& nums) {
    int i = 1, ans = 0;
    insert(nums[0]);
    for (i = 1; i < nums.size(); ++i) {
      auto x = find(nums[i]) ^ nums[i];
      // cout<<x<<endl;
      ans = max(ans, x);
      insert(nums[i]);
    }
    return ans;
  }
};