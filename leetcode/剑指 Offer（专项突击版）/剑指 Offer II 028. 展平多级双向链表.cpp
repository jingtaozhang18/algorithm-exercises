// https://leetcode-cn.com/problems/Qv1Da2/
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

class Solution {
 public:
  Node* flatten(Node* head) {
    Node *tn, *t = head, *ci;
    while (t) {
      if (t->child) {
        tn = t->next;
        ci = flatten(t->child);
        t->next = ci;
        ci->prev = t;
        while (ci->next) ci = ci->next;
        ci->next = tn;
        if (tn) tn->prev = ci;
        t->child = nullptr;
        t = tn;
      } else {
        t = t->next;
      }
    }
    return head;
  }
};