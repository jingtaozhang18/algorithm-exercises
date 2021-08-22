// https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int kthToLast(ListNode* head, int k) {
      ListNode*first=head, *second=head;
      while(k--) first=first->next;
      while(first) first=first->next, second=second->next;
      return second->val;
    }
};