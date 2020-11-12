// https://leetcode-cn.com/problems/merge-k-sorted-lists/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *t=new ListNode(0), *head=t, *c;
        int i,j;
        do{
            c=nullptr;
            for(int i=0;i<lists.size();++i){
                if(lists[i]&&(!c||lists[i]->val<c->val)) c=lists[i],j=i;
            }
            if(c) t->next=c, lists[j]=lists[j]->next, t=t->next;
        }while(c);
        return head->next;
    }
};