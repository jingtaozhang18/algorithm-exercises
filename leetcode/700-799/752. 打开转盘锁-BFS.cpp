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
        set <string> st;
        queue <string> que;
        jbuild(deadends);
        if (jdead("0000")) return -1; // 判断起点是否合法
        que.push("0000");
        st.insert("0000");
        string now;
        int i, nnow = 1, nnext = 0, step = 0;
        while (!que.empty()) {
            now = que.front();
            que.pop();
            if (!nnow) step++, nnow = nnext, nnext = 0; // 迭代到下一层
            nnow--; // 当前层数减1
            if (now == target) return step;
            for (i = 0; i < 4; ++i) {
                now[i] = jround(now[i], 1);
                if (st.find(now) == st.end() && !jdead(now)) st.insert(now), que.push(now), nnext++;
                now[i] = jround(now[i], -2);
                if (st.find(now) == st.end() && !jdead(now)) st.insert(now), que.push(now), nnext++;
                now[i] = jround(now[i], 1);
            }
        }
        return -1;
    }
};