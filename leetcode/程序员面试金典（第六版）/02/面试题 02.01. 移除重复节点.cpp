// https://leetcode-cn.com/problems/remove-duplicate-node-lcci/
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
    ListNode* removeDuplicateNodes(ListNode* head) {
      if(!head) return head;
      set<int> st;
      ListNode *t=head, *f=nullptr;
      while(t){
        if(st.find(t->val)==st.end())
        {
          st.insert(t->val);
          f=t,t=t->next;
        }
        else 
        {
          f->next=t->next;
          delete t;
          t=f->next;
        }
      }
      return head;
    }
};