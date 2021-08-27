// https://leetcode-cn.com/problems/linked-list-random-node/
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
  ListNode* head;
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least
     one node. */
  Solution(ListNode* head) { this->head = head; }

  /** Returns a random node's value. */
  int getRandom() {
    ListNode* t = head;
    int pos = 1, ans;
    while (t) {
      if (rand() % pos == 0) ans = t->val;
      t = t->next;
      ++pos;
    }
    return ans;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */