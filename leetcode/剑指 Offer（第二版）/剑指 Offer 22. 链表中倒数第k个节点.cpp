// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *first=head, *second=head;
        while(k--&&first)first=first->next;
        if(!k) return nullptr;
        while(first)first=first->next,second=second->next;
        return second;
    }
};

// 复习
class Solution_1 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast=head, *slow=head;
        while(k&&fast) fast=fast->next, --k;
        if(k==0){
            while(fast) fast=fast->next, slow=slow->next;
            return slow;
        }else{
            return nullptr;
        }
    }
};

// 复习
class Solution_2 {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *fast=head, *slow=head;
        while(fast&&k) fast=fast->next, --k;
        if(k) return nullptr;
        while(fast) fast=fast->next, slow=slow->next;
        return slow;
    }
};