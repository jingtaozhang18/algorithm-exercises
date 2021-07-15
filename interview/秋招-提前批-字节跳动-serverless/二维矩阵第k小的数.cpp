#include <bits/stdc++.h>
using namespace std;

// 矩阵中每个元素都小于它右边和下边的元素

struct node{
    int i, j, val;
    node(int i, int j, int val):i(i),j(j),val(val){}
    
    bool operator<(const node& other)const{
        return this->val<other.val;
    }
};

int calc(vector<vector<int>>& arr, int k){
    int m=arr.size();
    int n=arr[0].size();
    // 输入验证
    if(k<=0) return -1;
    if(k>m*n) return -1;
    // 
    priority_queue<node> que;
    unordered_set<int> st;
    que.push(node(0,0,arr[0][0])); st.insert(0);
    int ans, i, j, x, a, b;
    while(k--){
        ans=que.top().val;
        i=que.top().i, j=que.top().j;
        que.pop();
        if(i+1<m){
            a=i+1, b=j;
            x=a*n+b;
            if(st.find(x)==st.end()){
                que.push(node(a, b, arr[a][b]));
                st.insert(x);
            }
        }
        if(j+1<n){
            a=i, b=j+1;
            x=a*n+b;
            if(st.find(x)==st.end()){
                que.push(node(a, b, arr[a][b]));
                st.insert(x);
            }
        }
        return ans;
    }
}


int main() {
    //int a;
    //cin >> a;
    cout << "Hello World!" << endl;
}


// 1 2 4 6 
// 3 7 8 9
// 5
    
// 1, 2, 3, 4, 6, 7, 8