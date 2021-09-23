// https://leetcode-cn.com/problems/split-linked-list-in-parts/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int length = 0;
    ListNode *t = head, *father, *nh;
    while (t) t = t->next, ++length;
    int len = length / k;
    int mod = length % k;
    t = head;
    vector<ListNode *> ans;
    for (int i = 0; i < k; ++i) {
      int times = len;
      if (mod-- > 0) ++times;
      nh = t, father = nullptr;
      while (t && times) father = t, t = t->next, --times;
      ans.push_back(nh);
      if (father) father->next = nullptr;
    }
    return ans;
  }
};