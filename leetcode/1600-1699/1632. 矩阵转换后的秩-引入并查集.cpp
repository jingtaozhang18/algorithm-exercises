// https://leetcode-cn.com/problems/rank-transform-of-a-matrix/
#include<bits/stdc++.h>
using namespace std;

class UnionFind {
// 作者：lucifer1004
// 链接：https://leetcode-cn.com/problems/rank-transform-of-a-matrix/solution/bing-cha-ji-tuo-bu-pai-xu-by-lucifer1004/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
  int n;
  vector<int> parent, size;

public:
  UnionFind(int n) {
    this->n = n;
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }

  int find(int idx) {
    if (parent[idx] == idx)
      return idx;
    return parent[idx] = find(parent[idx]);
  }

  void connect(int a, int b) {
    int fa = find(a), fb = find(b);
    if (fa != fb) {
      if (size[fa] > size[fb]) {
        parent[fb] = fa;
        size[fa] += size[fb];
      } else {
        parent[fa] = fb;
        size[fb] += size[fa];
      }
    }
  }
};


struct node{
    int val, i, j, rank;
    node(){}
    node(int val, int i, int j):val(val),i(i),j(j),rank(0){}
    bool operator<(const node& other) const{
        // if(val==other.val) return rank>other.rank;
        return val<other.val;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int i,j,k,x,y,m=matrix.size(), n=matrix[0].size();
        node nd, ond;
        // 建立并查集
        UnionFind uf(n * m);
        for (int i = 0; i < m; ++i) {
            map<int, vector<int>> mp;
            for (int j = 0; j < n; ++j)
                mp[matrix[i][j]].emplace_back(i * n + j);
            for (auto p : mp) {
                for (int k = 0; k + 1 < p.second.size(); ++k)
                    uf.connect(p.second[k], p.second[k + 1]);
            }
        }
        for (int j = 0; j < n; ++j) {
            map<int, vector<int>> mp;
            for (int i = 0; i < m; ++i)
                mp[matrix[i][j]].emplace_back(i * n + j);
            for (auto p : mp) {
                for (int k = 0; k + 1 < p.second.size(); ++k)
                    uf.connect(p.second[k], p.second[k + 1]);
            }
        }
        // 将所有元素根据val从小到达排列
        vector<node> arr;
        for(i=0;i<m;++i) for(j=0;j<n;++j) arr.push_back(node(matrix[i][j],i,j));
        sort(arr.begin(), arr.end());
        // row_index 行方向上当前的最大rank, row_val 行方向上当前最大rank对应的值
        // col_index 列方向上当前的最大rank, row_val 列方向上当前最大rank对应的值
        vector<int> row_index(m,0), row_val(m,INT_MIN), col_index(n,0), col_val(n, INT_MIN);
        vector<vector<int>> ans(m, vector<int>(n));
        for(i=0;i<m*n;++i){ // 从val最小的开始遍历
            nd=arr[i];
            arr[i].rank=max(row_index[nd.i], col_index[nd.j]);
            // 相同的val的node，需要找到他们所在行列的最大rank对应的那个node开始处理
            for(k=i,j=i+1;j<m*n&&arr[j].val==nd.val;++j) {
                arr[j].rank=max(row_index[arr[j].i], col_index[arr[j].j]);
                if(arr[j].rank>arr[k].rank) k=j;
            }
            nd=arr[k], arr[k]=arr[i], arr[i]=nd;
            // nd是当前满足条件的node
            x=row_index[nd.i], y=col_index[nd.j];
            if(nd.val>row_val[nd.i]) ++x, row_val[nd.i]=nd.val;
            if(nd.val>col_val[nd.j]) ++y, col_val[nd.j]=nd.val;
            x=max(x, y);
            ans[nd.i][nd.j]=x;
            row_index[nd.i]=col_index[nd.j]=x;
            // 和nd处于同一类的node的直接赋值，并将他们在arr中移到前面
            for(--j;j>i;){
                ond=arr[j];
                if(uf.find(ond.i*n+ond.j)==uf.find(nd.i*n+nd.j)){
                    ans[ond.i][ond.j]=row_index[ond.i]=col_index[ond.j]=x;
                    swap(arr[++i], arr[j]);
                }else{
                    --j;
                }
            }
        }
        return ans;
    }
};