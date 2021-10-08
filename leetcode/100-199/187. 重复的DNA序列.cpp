// https://leetcode-cn.com/problems/repeated-dna-sequences/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<unsigned long long, int> mp;
        vector<string> ans;
        int i, m = s.size(), n = 10;
        unsigned long long x = 0, base = pow(26, n - 1);
        for (i = 0; i < m; ++i)
        {
            if (i >= n)
            {
                x -= base * (s[i - n] - 'a');
            }
            x *= 26;
            x += s[i] - 'a';
            if (i >= n - 1)
            {
                ++mp[x];
                if (mp[x] == 2)
                {
                    ans.push_back(s.substr(i - n + 1, n));
                }
            }
        }
        return ans;
    }
};