// https://leetcode-cn.com/problems/linked-list-cycle-lcci/
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
    ListNode *detectCycle(ListNode *head) {
      if(!head) return nullptr;
      ListNode *fast=head, *slow=head;
      int times=0;
      while(fast)
      {
        fast=fast->next;
        if(fast) fast=fast->next;
        else return nullptr;
        slow=slow->next;
        times++;
        if(fast==slow) break;
      }
      if(!fast) return nullptr; // 错误点，出循环也可能是无路可走了
      fast=slow=head;
      while(times--) fast=fast->next; // 走出环路的长度
      while(fast!=slow) fast=fast->next, slow=slow->next;
      return fast;
    }
};