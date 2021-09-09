// https://leetcode-cn.com/problems/SLwz0R/
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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *fast = head, *slow = head;
    ++n;
    while (n-- && fast) fast = fast->next;
    if (n != -1) { // 没有把n走完，说明去掉的是头节点
      slow = head;
      head = head->next;
      delete slow;
      return head;
    }
    while (fast) fast = fast->next, slow = slow->next;
    fast = slow->next;
    slow->next = slow->next->next;
    delete fast;
    return head;
  }
};