// https://leetcode-cn.com/problems/aMhZSa/
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
  bool calc(ListNode *&head, ListNode *node) {
    if (node->next)
      if (calc(head, node->next) == false) return false;
    if (head->val != node->val) return false;
    head = head->next;
    return true;
  }
  bool isPalindrome(ListNode *head) { return calc(head, head); }
};