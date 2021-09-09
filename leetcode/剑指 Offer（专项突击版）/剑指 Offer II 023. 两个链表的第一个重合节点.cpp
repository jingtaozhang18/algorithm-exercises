// https://leetcode-cn.com/problems/3u1WK4/
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *t1 = headA, *t2 = headB;
    while (t1 != t2) {
      if (t1)
        t1 = t1->next;
      else
        t1 = headB;
      if (t2)
        t2 = t2->next;
      else
        t2 = headA;
    }
    return t1;
  }
};