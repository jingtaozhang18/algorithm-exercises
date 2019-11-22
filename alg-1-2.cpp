#include <iostream>
#include <queue>

using namespace std;

int w(int m[8][8], int i, int j, int k){
    return m[i][j]+m[j][k]+m[i][k];
}
struct state{
    int i;
    int j;
};

int main(){
    int ori[8][8]={
        {0, 14, 25, 27, 10, 11, 24, 16},
        {0, 0 , 18, 15, 27, 28, 16, 14},
        {0, 0 , 0 , 19, 14, 19, 16, 10},
        {0, 0 , 0 , 0 , 22, 23, 15, 14},
        {0, 0 , 0 , 0 , 0 , 14, 13, 20},
        {0, 0 , 0 , 0 , 0 , 0 , 15, 18},
        {0, 0 , 0 , 0 , 0 , 0 , 0 , 27},
        {0, 0 , 0 , 0 , 0 , 0 , 0 , 0}
    };
    int dp[8][8];
    int st[8][8];
    int i,j,k;
    memset(dp, 0, sizeof(dp));
    memset(st, 0, sizeof(st));

    int row, col, min_c, pos_c, cur_c;
    for(i=1; i<=7; ++i){
        for(row=7-i; row>=1; --row){
            col=row+i;
            min_c=0x7fffffff;
            
            for(k=row; k<col; ++k){
                cur_c=dp[row][k] + dp[k+1][col] + w(ori,row-1,k,col);
                if(cur_c<min_c){
                    min_c=cur_c;
                    pos_c=k;
                }
            }
            dp[row][col]=min_c;
            st[row][col]=pos_c;
        }
    }
    for(i=0;i<8;++i){
        for(j=0;j<8;++j){
            cout << dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout << "最小值:" << dp[1][7] <<endl;
    cout << "集合T:" << endl;
    queue<state> que;
    state con = {1,7};
    state fro;
    que.push(con);
    while(!que.empty()){
        fro = que.front();
        que.pop();
        k=st[fro.i][fro.j];
        if (k-fro.i>1) {
            cout << fro.i << "--" << k+1 << endl;
            con.i=fro.i, con.j=k;
            que.push(con);
        }
        if (fro.j-k>1) {
            cout << k+1 << "--" << fro.j+1 << endl;
            con.i=k+1, con.j=fro.j;
            que.push(con);
        }
    }
    return 0;
}