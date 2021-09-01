// https://leetcode-cn.com/problems/UHnkqh/
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
  ListNode* reverseList(ListNode* head) {
    ListNode *a, *b, *c;
    a = nullptr, b = head;
    while (b) {
      c = b->next;
      b->next = a;
      a = b, b = c;
    }
    return a;
  }
};