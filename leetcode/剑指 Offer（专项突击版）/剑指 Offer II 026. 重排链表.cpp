// https://leetcode-cn.com/problems/LGjMqU/
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
  void reorderList(ListNode *head) {
    if (!head || !head->next) return;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // slow 是长前半段的最后一个
    ListNode *a, *b, *c, *ans = new ListNode(0), *t;
    a = nullptr, b = slow->next, slow->next = nullptr;
    while (b) {
      c = b->next;
      b->next = a;
      a = b, b = c;
    }
    // a是短后半段的最后一个
    b = head, c = a, t = ans;
    while (b || c) {
      if (b) t->next = b, b = b->next, t = t->next;
      if (c) t->next = c, c = c->next, t = t->next;
    }
    head = ans->next;
  }
};