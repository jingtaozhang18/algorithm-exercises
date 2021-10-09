// https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/
#include <bits/stdc++.h>
using namespace std;

class SummaryRanges
{
public:
    map<int, int> mp;
    SummaryRanges()
    {
    }

    void addNum(int val)
    {
        if (mp.size() == 0)
        {
            mp[val] = 1;
            return;
        }
        auto p = mp.upper_bound(val);
        auto q = p;
        if (p == mp.begin())
            p = mp.end();
        else
            --p;
        if (p == mp.end())
        {
            if (q != mp.end() && val + 1 == q->first)
            {
                mp[q->first - 1] = q->second + 1;
                mp.erase(q);
            }
            else
            {
                mp[val] = 1;
            }
        }
        else
        {
            if (val < p->first + p->second)
                ; // 不用处理了
            else if (val == p->first + p->second)
            {
                if (q != mp.end() && val + 1 == q->first)
                { // 合并区间
                    mp[p->first] = p->second + 1 + q->second;
                    mp.erase(q);
                }
                else
                {
                    ++p->second;
                }
            }
            else
            {
                if (q != mp.end() && val + 1 == q->first)
                {
                    mp[q->first - 1] = q->second + 1;
                    mp.erase(q);
                }
                else
                {
                    mp[val] = 1;
                }
            }
        }
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for (auto &p : mp)
        {
            ans.push_back({p.first, p.first + p.second - 1});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */