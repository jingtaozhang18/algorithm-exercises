// https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/
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

// 题干只要求换值，傻孩子，就不能多花点时间认真看题？
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *fk=head, *ffk, *bk, *fbk, *fast, *slow=head;
        int i;
        for(i=0;i<k-1;++i) ffk=fk,fk=fk->next;
        fbk=fk, fast=fk->next;
        while(fast) fast=fast->next, fbk=slow, slow=slow->next;
        bk=slow;
        // cout<<ffk->val<<" "<<fk->val<<" "<<fbk->val<<" "<<bk->val<<endl;
        if(fk==bk) return head;
        if(fk==head||bk==head){
            if(fk==head){
                fbk->next=fk;
                bk->next=fk->next;
                fk->next=nullptr;
                return bk;
            }else{
                ffk->next=bk;
                fk->next=bk->next;
                bk->next=nullptr;
                return fk;
            }
        }else{ // 正常节点
            ffk->next=bk;
            fbk->next=fk;
            swap(fk->next, bk->next);
        }
        return head;
    }
};