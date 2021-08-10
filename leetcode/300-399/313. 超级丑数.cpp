// https://leetcode-cn.com/problems/super-ugly-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<unsigned long > st;
        priority_queue<unsigned long , vector<unsigned long>, greater<unsigned long>> que;
        que.push(1);
        st.insert(1);
        unsigned long ans=0;
        while(n--){
            while(que.top()==ans) que.pop();
            ans=que.top();
            que.pop();
            for(auto &prime:primes){
                if(st.find(prime*ans)==st.end()){
                    que.push(ans*prime);
                    st.insert(ans*prime);
                }
            }
        }
        return ans;
    }
};