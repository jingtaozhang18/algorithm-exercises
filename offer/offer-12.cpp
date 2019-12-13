#include<iostream>
using namespace std;
class Solution {
public:
    
    bool findPath(char* matrix, int i, int j, int rows, int cols, char* str, bool path[])
    {
        if(*str==0) return true;
        // cout<<i<<" "<<j<<" "<<(path[(i-1)*cols+j]==false)<<" "<<matrix[(i-1)*cols+j]<<endl;
        if(i>0 && path[(i-1)*cols+j]==false && matrix[(i-1)*cols+j]==*str){
            path[(i-1)*cols+j]=true;
            if(findPath(matrix, i-1, j, rows, cols, str+1, path))
                return true;
            path[(i-1)*cols+j]=false;
        }
        if(j>0&&path[i*cols+j-1]==false&&matrix[i*cols+j-1]==*str){
            path[i*cols+j-1]=true;
            if(findPath(matrix, i, j-1, rows, cols, str+1, path))
                return true;
            path[i*cols+j-1]=false;
        }
        
        if(i+1<rows&&path[(i+1)*cols+j]==false&&matrix[(i+1)*cols+j]==*str){
            path[(i+1)*cols+j]=true;
            if(findPath(matrix, i+1, j, rows, cols, str+1, path))
                return true;
            path[(i+1)*cols+j]=false;
        }
        // for(int a=0;a<rows;++a){
        //     for(int b=0;b<cols;++b){
        //         cout<<path[a*cols+b]<<" ";
        //     }
        //     cout <<endl;
        // }
        // cout<<endl;
        // cout<<i<<" "<<j<<" "<<path[i*cols+j+1]<<" "<<matrix[i*cols+j+1]<<" "<<*str<<endl;
        if(j+1<cols&&path[i*cols+j+1]==false&&matrix[i*cols+j+1]==*str){
            path[i*cols+j+1]=true;
            if(findPath(matrix, i, j+1, rows, cols, str+1, path))
                return true;
            path[i*cols+j+1]=false;
        }
        return false;
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(rows<=0||cols<=0) return false;
        if(str==nullptr||*str==0) return false;
        bool path[rows*cols];
        memset(path,false,sizeof(path));

        // for(int a=0;a<rows;++a){
        //     for(int b=0;b<cols;++b){
        //         cout<<path[a*cols+b]<<" ";
        //     }
        //     cout <<endl;
        // }
        // cout<<endl;


        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(matrix[i*cols+j]==*str){
                    path[i*cols+j]=true;
                    bool ans=findPath(matrix,i,j,rows,cols,str+1,path);
                    // cout << "i:"<<i<<", j:"<<j<<", ans:"<<ans<<endl;
                    if(ans)
                        return true;
                    memset(path,0,sizeof(path));
                }
            }
        }
        return false;
    }
};

int main(void){
    char * ch="ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    char * str="SLHECCEIDEJFGGFIE";

    Solution().hasPath(ch,5,8,str);
    return 0;
}