// https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
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
    void jgo(ListNode* head){ // 反转链表
        ListNode *a=nullptr,*b;
        while(head) b=head->next, head->next=a, a=head, head=b;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*ans=nullptr,*a,*b,*tail,*th;
        b=head,th=head; // th新的一段起点，tail上一段的尾巴
        int i=0;
        while(b){
            i++;
            if(i==k){
                a=b->next; // 保持连续
                b->next=nullptr; // 断开，准备反转
                jgo(th); // 反转
                if(tail) tail->next=b;
                if(!ans) ans=b;
                tail=th, th=a, b=a; // 修复指针
                i=0;
            }else b=b->next;
        }
        if(i&&tail) tail->next=th; // 不恰好为整段
        return ans?ans:head;
    }
};