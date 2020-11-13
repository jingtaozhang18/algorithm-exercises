// https://leetcode-cn.com/problems/reorder-list/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next) return; // 错误点，特例分析不足
        ListNode *fast=head, *slow=head, *tail=nullptr, *a, *b, *t;
        bool f;
        // 找到中间节点
        while(fast->next){
            fast=fast->next;if(fast->next)fast=fast->next;
            tail=slow, slow=slow->next;
        }
        tail->next=nullptr;
        // 逆序后半段
        a=nullptr;
        while(slow){
            b=slow->next, slow->next=a, a=slow, slow=b;
        }
        // 合并head和a链表
        b=head,f=true;
        tail=new ListNode(0), t=tail;
        while(a&&b){
            if(!f) t->next=a, a=a->next;
            else t->next=b, b=b->next;
            t=t->next, f=!f;
        }
        if(a)t->next=a; if(b)t->next=b;
        head=tail->next;
        return;
    }
};