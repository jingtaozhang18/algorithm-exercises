// https://leetcode-cn.com/problems/sum-lists-lcci/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode *ans=new ListNode(0), *t=ans;
      bool flag=false;
      while(l1||l2||flag)
      {
        int num=0;
        if(l1) num+=l1->val, l1=l1->next;
        if(l2) num+=l2->val, l2=l2->next;
        if(flag) num++;
        t->next=new ListNode(num%10), t=t->next;
        flag=num/10;
      }
      return ans->next;
    }
};