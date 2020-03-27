#include<pthread.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int M, N;
int **a;
int *b;
int *ans;

void *func(void *args){
    int k=*(int *)args;
    int gap=M/4;
    int end;
    if(k==3){
        k=k*gap;
        end=M;
    }
    else{
        k=k*gap;
        end=k+gap;
    }
    // cout << k << "\t" << end<<endl;
    for(;k<end;k++){
        ans[k]=0;
        for(int i=0;i<N;++i){
            ans[k]+=(a[k][i]*b[i]);
        }
    }
    pthread_exit(NULL);
};
int main(void){
    cin >> M >> N;
    a=new int *[M];
    b=new int[N];
    ans=new int[M];
    for(int i=0;i<M;++i) {a[i]=new int[N]; for(int j=0;j<N;++j)cin>>a[i][j];}
    for(int i=0;i<N;++i) cin>>b[i];

    int gap=M/4;

    pthread_t tids[4];
    int i;
    int pindex[4];
    for(i=0;i<4;i++){
        pindex[i]=i;
        if(pthread_create(&tids[i],NULL,func, (void*)&pindex[i])){
            perror("pthread_create");
            exit(1);
        }
    }
    for(i=0;i<4;++i){
        pthread_join(tids[i],NULL);
    }
    for(i=0;i<M;++i) cout<<"ans:" << ans[i]<<endl;
    return 0;
}

