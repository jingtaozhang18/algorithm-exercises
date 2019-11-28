#include "iostream"
#include "string"
using namespace std;

int test_func(bool a[]){
    a[0]=true;
    return 0;
}

int main(){
    bool a[2];
    a[0]=false;
    test_func(a);
    cout<<a[0]<<endl;



    // string a="abc";
    // a[1]='B';
    // cout<<a<<endl;



    // char a='a';
    // int con[256];
    // memset(con,0,sizeof(con));
    // con[a]=1;
    // for(int i=0;i<256;++i){
    //     cout<<i<<"\t"<<con[i]<<endl;
    //     if(con[i]==1) cout<<(char)i<<endl;
    // }



    // int *a = new int[10];
    // int *b = new int[10];
    // const int *p1 = a;
    // const int *p2 = b;
    // cout << p1-p2 << endl;
}