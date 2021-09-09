// https://leetcode-cn.com/problems/4ueAj6/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;

  Node() {}

  Node(int _val) {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node* _next) {
    val = _val;
    next = _next;
  }
};

class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    if (!head) {
      Node* ans = new Node(insertVal);
      ans->next = ans;
      return ans;
    }
    Node* ans = head;
    while (!((head->val <= insertVal && head->next->val >= insertVal) ||
             ((head->next->val >= insertVal || head->val <= insertVal) &&
              head->val > head->next->val))) {
      head = head->next;
      if (head == ans) break;
    }
    Node* t = head->next;
    head->next = new Node(insertVal, t);
    return ans;
  }
};