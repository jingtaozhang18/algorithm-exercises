// https://leetcode-cn.com/problems/7WHec2/
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
  ListNode* merge(ListNode* a, ListNode* b) {
    ListNode *ans = new ListNode(0), *ta = ans;
    while (a && b) {
      if (a->val < b->val)
        ta->next = a, a = a->next;
      else
        ta->next = b, b = b->next;
      ta = ta->next;
    }
    if (a) ta->next = a;
    if (b) ta->next = b;
    return ans->next;
  }

  ListNode* stepSort(ListNode* head, int step) {
    int i;
    ListNode *a, *b, *x, *c, *y, *d, *ans = nullptr;
    //     *** - ****** - ****** - ***
    a = nullptr, b = head, c = head, d = nullptr;
    while (c) {
      i = step;
      while (c && --i) {  // 第一段的末尾
        c = c->next;
      }
      if (c && c->next) {  // 进行归并
        x = c;
        c = c->next;
        x->next = nullptr;
        i = step, d = c;
        while (d && --i) {
          d = d->next;
        }
        if (d) {
          y = d;
          d = d->next;
          y->next = nullptr;
        }
        x = merge(b, c);
        if (!ans) ans = x;
        if (!a) {
          a = x;
          while (a->next) a = a->next;
        } else {
          a->next = x;
          while (a->next) a = a->next;
        }
        b = c = d;
      } else {
        if (a) a->next = b;
        break;
      }
    }
    return ans;
  }

  ListNode* sortList(ListNode* head) {
    int step, num = 0;
    ListNode* x = head;
    while (x) ++num, x = x->next;
    for (step = 1; step < num; step <<= 1) {
      head = stepSort(head, step);
    }
    return head;
  }
};