// https://leetcode-cn.com/problems/odd-even-linked-list/
#include<bits/stdc++.h>
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
  ListNode* oddEvenList(ListNode* head) {
    ListNode* Ghead = new ListNode(), * gt = Ghead;
    ListNode* Ohead = new ListNode(), * ot = Ohead;
    bool flag = true;
    while (head) {
      if (flag) gt->next = head, gt = gt->next;
      else  ot->next = head, ot = ot->next;
      head = head->next, flag = !flag;
    }
    gt->next = Ohead->next;
    ot->next = nullptr;
    delete Ohead;
    head = Ghead->next;
    delete Ghead;
    return head;
  }
};