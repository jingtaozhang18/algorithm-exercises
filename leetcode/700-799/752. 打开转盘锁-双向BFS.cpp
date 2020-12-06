// https://leetcode-cn.com/problems/open-the-lock/
#include<bits/stdc++.h>
using namespace std;

struct node {
    node *next[10];

    node() { memset(next, 0, sizeof next); }
};

class Solution {
public:
    node *head;

    char jround(char c, int i) { return '0' + (((c - '0') + i + 20) % 10); }

    void jbuild(vector <string> &deadends) {
        head = new node();
        node *tmp;
        for (auto str: deadends) {
            tmp = head;
            for (int i = 0; i < str.size(); ++i) {
                if (!tmp->next[str[i] - '0']) tmp->next[str[i] - '0'] = new node();
                tmp = tmp->next[str[i] - '0'];
            }
        }
    }

    bool jdead(string now) {
        node*t=head;
        for(int i=0;i<4;++i){
            if(!t->next[now[i]-'0']) return false;
            t=t->next[now[i]-'0'];
        }
        return true;
    }

    int openLock(vector <string> &deadends, string target) {
        map <string, int> fst;
        map <string, int> bst;
        queue <string> fque;
        queue <string> bque;
        jbuild(deadends);
        if (jdead("0000")||jdead(target)) return -1; // 判断起点是否合法
        fque.push("0000"), fst["0000"]=0;
        bque.push(target), bst[target]=0;
        string now;
        int i,j, fstep=0, bstep=0, fnum=1, bnum=1, t;
        while (!fque.empty()||!bque.empty()) {
            t=fnum, fnum=0,fstep++;;
            while(t--){
                now = fque.front(); fque.pop();
                if (bst.find(now)!=bst.end()) return fstep+bst[now]-1;
                for (i = 0; i < 4; ++i) {
                    now[i] = jround(now[i], 1);
                    if (fst.find(now) == fst.end() && !jdead(now)) fst[now]=fstep, fque.push(now), fnum++;
                    now[i] = jround(now[i], -2);
                    if (fst.find(now) == fst.end() && !jdead(now)) fst[now]=fstep, fque.push(now), fnum++;
                    now[i] = jround(now[i], 1);
                }
            }
            t=bnum, bnum=0, bstep++;
            while(t--){
                now = bque.front(); bque.pop();
                if (fst.find(now)!=fst.end()) return fst[now]+bstep-1;
                for (i = 0; i < 4; ++i) {
                    now[i] = jround(now[i], 1);
                    if (bst.find(now) == bst.end() && !jdead(now)) bst[now]=bstep, bque.push(now), bnum++;
                    now[i] = jround(now[i], -2);
                    if (bst.find(now) == bst.end() && !jdead(now)) bst[now]=bstep, bque.push(now), bnum++;
                    now[i] = jround(now[i], 1);
                }
            }
        }
        return -1;
    }
};