#include "iostream"
using namespace std;

int test_func(){
    return 0;
}

int main(){
    char a='a';
    int con[256];
    memset(con,0,sizeof(con));
    con[a]=1;
    for(int i=0;i<256;++i){
        cout<<i<<"\t"<<con[i]<<endl;
        if(con[i]==1) cout<<(char)i<<endl;
    }



    // int *a = new int[10];
    // int *b = new int[10];
    // const int *p1 = a;
    // const int *p2 = b;
    // cout << p1-p2 << endl;
}