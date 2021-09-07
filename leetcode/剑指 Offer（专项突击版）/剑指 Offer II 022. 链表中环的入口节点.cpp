// https://leetcode-cn.com/problems/c32eOV/
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
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    do {
      if (fast && fast->next)
        fast = fast->next->next;
      else
        return nullptr;
      slow = slow->next;
    } while (fast != slow);
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};