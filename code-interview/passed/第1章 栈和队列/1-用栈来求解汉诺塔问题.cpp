#include<iostream>
#include<string.h>
using namespace std;

const string jleft="left";
const string jmid="mid";
const string jright="right";

int process(int num,string from, string to){
    if(num==1){
        if(from==jmid||to==jmid){ // 一步移动
            cout<<"Move "<<num<<" from "<<from<<" to "<<to<<endl;
            return 1;
        }else{
            cout<<"Move "<<num<<" from "<<from<<" to "<<jmid<<endl;
            cout<<"Move "<<num<<" from "<<jmid<<" to "<<to<<endl;
            return 2;
        }
    }else{
        if(from==jmid||to==jmid){ // 一步移动
            string another((from==jleft||to==jleft)?jright:jleft);
            int nums1=process(num-1,from,another);
            cout<<"Move "<<num<<" from "<<from<<" to "<<to<<endl;
            int nums2=1;
            int nums3=process(num-1,another,to);
            return nums1+nums2+nums3;
        }else{
            int nums1=process(num-1,from,to);
            cout<<"Move "<<num<<" from "<<from<<" to "<<jmid<<endl;
            int nums2=1;
            int nums3=process(num-1,to,from);
            cout<<"Move "<<num<<" from "<<jmid<<" to "<<to<<endl;
            int nums4=1;
            int nums5=process(num-1,from,to);
            return nums1+nums2+nums3+nums4+nums5;
        }
    }
}
int main(void){
    int N;
    cin>>N;
    int ans=process(N,jleft,jright);
    cout<<"It will move "<<ans<<" steps.";
}