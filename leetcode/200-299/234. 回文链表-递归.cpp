// https://leetcode-cn.com/problems/palindrome-linked-list/
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
  bool jcalc(ListNode *&head, ListNode *t) {
    if (t->next)
      if (jcalc(head, t->next) == false) return false;
    if (head->val != t->val) return false;
    head = head->next;
    return true;
  }
  bool isPalindrome(ListNode *head) { return jcalc(head, head); }
};