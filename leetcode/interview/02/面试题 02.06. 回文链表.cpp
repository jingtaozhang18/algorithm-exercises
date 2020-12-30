// https://leetcode-cn.com/problems/palindrome-linked-list-lcci/
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
    bool isPalindrome(ListNode* head) {
      if(!head||!head->next) return true;
      ListNode*f=head,*s=head;
      while(f->next)
      {
        f=f->next;
        if(f->next)
        {
          f=f->next;
          s=s->next;
        }
      }
      // s是奇数长度时的中间节点，偶数长度时前半段最后的节点
      f=s->next, s->next=nullptr;
      // 对f开头的链表反向
      ListNode *a=nullptr, *b=f;
      while(b)
      {
        f=b->next, b->next=a, a=b, b=f;
      }
      // a是反向后链表的开头
      while(head&&a) // 忽略了奇数长度时的中间节点
      {
        if(head->val!=a->val) return false;
        head=head->next, a=a->next;
      }
      return true;
    }
};