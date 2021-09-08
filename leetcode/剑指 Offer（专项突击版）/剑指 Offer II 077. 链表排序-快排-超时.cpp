// https://leetcode-cn.com/problems/7WHec2/
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
  ListNode *sortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *left = new ListNode(0), *tl = left;
    ListNode *right = new ListNode(0), *tr = right;
    ListNode *pivot = head, *tp = head;
    ListNode *th = nullptr;
    head = head->next;
    while (head) {
      if (head->val < pivot->val) {
        tl->next = head;
        tl = tl->next;
      } else if (head->val > pivot->val) {
        tr->next = head;
        tr = tr->next;
      } else {
        tp->next = head;
        tp = tp->next;
      }
      head = head->next;
    }
    tp->next = tl->next = tr->next = nullptr;
    left = sortList(left->next);
    right = sortList(right->next);
    if (left) {
      if (!th) head = left, th = head;
      while (th->next) th = th->next;
    }
    if (!th)
      head = pivot, th = head;
    else
      th->next = pivot;
    while (th->next) th = th->next;
    if (right) {
      th->next = right;
    }
    return head;
  }
};