// https://leetcode-cn.com/problems/vvXgSW/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *head = new ListNode(), *cur = head, *t;
    int i, x;
    while (true) {
      t = nullptr;
      i = 0;
      for (auto& e : lists) {
        if (e) {
          if (!t)
            t = e, x = i;
          else {
            if (e->val < t->val) {
              t = e;
              x = i;
            }
          }
        }
        ++i;
      }
      if (!t) break;
      cur->next = t;
      cur = cur->next;
      lists[x] = lists[x]->next;
    }
    return head->next;
  }
};