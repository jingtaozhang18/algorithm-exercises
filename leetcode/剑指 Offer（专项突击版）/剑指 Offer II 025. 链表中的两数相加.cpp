// https://leetcode-cn.com/problems/lMSNwu/
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
  ListNode* calc(ListNode* t) {
    ListNode *a, *b, *c;
    c = nullptr, a = t;
    while (a) {
      b = a->next;
      a->next = c;
      c = a, a = b;
    }
    return c;
  }
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = calc(l1);
    l2 = calc(l2);
    int j = 0;
    ListNode *ans = new ListNode(0), *t = ans;
    while (l1 || l2 || j) {
      if (l1) j += l1->val, l1 = l1->next;
      if (l2) j += l2->val, l2 = l2->next;
      t->next = new ListNode(j % 10);
      j /= 10;
      t = t->next;
    }
    return calc(ans->next);
  }
};