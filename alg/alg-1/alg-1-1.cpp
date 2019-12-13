#include <iostream>

using namespace std;

int main(){
    int ori[4][9]={
        {0, 5, 15, 40, 80, 90, 95, 98, 100},
        {0, 5, 15, 40, 60, 70, 73, 74, 75},
        {0, 4, 26, 40, 45, 50, 51, 52, 53},
    };

    int dp[4][9]={
        {0, 5, 15, 40, 80, 90, 95, 98, 100},
        {0, 5, 15, 40, 60, 70, 73, 74, 75},
        {0, 4, 26, 40, 45, 50, 51, 52, 53},
    };

    int status[4][9] = { // 第i个项目，投入status[i][j]元，使得在j元时，投前i个项目的收益最大
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
        {0, 1, 2, 3, 4, 5, 6, 7, 8},
    };

    int i, j, k, max_g, pos_g, cur_g;

    for(i=0;i<3;++i){
        for (j=0;j<9;++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    for(i=1; i<3; ++i){
        for (j=8; j>0; --j){
            max_g = dp[i-1][j];
            pos_g = 0;
            for(k=1; k<=j; ++k){
                cur_g = dp[i-1][j-k] + dp[i][k];
                if(cur_g>max_g){
                    max_g = cur_g;
                    pos_g = k;
                }
            }
            dp[i][j]=max_g;
            status[i][j]=pos_g;
        }
    }
    for(i=0;i<3;++i){
        for (j=0;j<9;++j){
            if (ori[i][j]==dp[i][j])
                cout << dp[i][j] << "\t";
            else
                cout << ori[i][j] << "->" <<dp[i][j] << "\t";
        }
        cout << endl;
    }

    for(i=0;i<3;++i){
        for (j=0;j<9;++j){
            cout << status[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
