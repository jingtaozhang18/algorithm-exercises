#include<vector>
#include<iostream>
using namespace std;
    
int InversePairs(vector<int> data) {
    int dataSize=data.size(),i,j,index;
    vector<int> copy;
    for(i=0;i<dataSize;++i) copy.push_back(data[i]);
    int size=2,ans=0,part,cI;
    while((size>>1) < dataSize){
        for(index=0; index<dataSize; index+=size){
            part=size>>1;
            i=min(index+part-1, dataSize-1), j=min(index+size-1, dataSize-1);
            cI=j;
            while(i>=index && j>=index+part){
                if(data[i]>data[j]){
                    ans+=j-index-part+1;
                    copy[cI--]=data[i--];
                }else{
                    copy[cI--]=data[j--];
                }
            }
            while(i>=index) copy[cI--]=data[i--];
            while(j>=index+part) copy[cI--]=data[j--];
        }
        for(i=0;i<dataSize;++i){
            data[i]=copy[i];
            cout << data[i] << " ";
        }
        cout<<"\t"<<ans<<endl;
        size=size<<1;
    }
    return ans;
}

int main(){
    int len,tep;
    vector<int> input;
    cin>>len;
    while(len--) { cin>>tep; input.push_back(tep); }
    cout << endl << InversePairs(input)<<endl;
}