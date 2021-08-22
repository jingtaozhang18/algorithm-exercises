// https://leetcode-cn.com/problems/partition-list-lcci/
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
    ListNode* partition(ListNode* head, int x) {
      ListNode *a = new ListNode(0);
      ListNode *b = new ListNode(0);
      ListNode *ta=a, *tb=b, *th=head;
      while(th){
        if(th->val<x) ta->next=th, ta=ta->next, th=th->next, tb->next=nullptr;
        else tb->next=th, tb=tb->next, th=th->next, tb->next=nullptr;
      }
      ta->next=b->next;
      return a->next;
    }
};