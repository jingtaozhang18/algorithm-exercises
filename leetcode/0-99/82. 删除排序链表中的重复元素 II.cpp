// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
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

// 父指针的用法，比较独特，踩了很多的坑
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        int val=head->val;
        ListNode *th=head, *fh=nullptr, *t, *p;
        while(th){
            for(t=th;t->next&&t->next->val==t->val;t=t->next); // 找到相同的最后一个
            if(t==th) {
                // if(!fh) head=th; // 第一个不重复的数字
                fh=th, th=th->next; // 当前位置没问题
            }else{
                // 从th删除到t
                if(fh) fh->next=t->next;
                else head=t->next;
                p = t->next;
                while(th&&th!=p){
                    t=th;
                    th=th->next;
                    delete t;
                }
                th=p;
            }
        }
        return head;
    }
};