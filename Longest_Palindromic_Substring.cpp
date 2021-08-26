#include <iostream>
#include <string>
using namespace std;
void cp(int**ma, int *len){
    int i, j, k;
    for(i=0;i<*len;i++){
        for(j=0;j<*len;j++){
            cout<< ma[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

        string s;
        getline(cin, s);
        //cout<<s<<endl;

        int len = s.size();
        string ss="";
        int i,j , k=0,max=0, i_index=0, j_index=0;
        int **ma = new int*[len];
        
        for(i=0;i<len-1;i++){
            ma[i] = new int[len]();
            ma[i][i]=1;
            ma[i][i+1] = (s[i]==s[i+1])?1:0;
        }
        ma[len-1] = new int[len]();
        ma[len-1][len-1] = 1;

        for(i=len-2;i>=0;i--){
            for(j=i+2;j<len;j++){
                if(ma[i+1][j-1]==1 && s[i]==s[j]){
                    ma[i][j] = 1;
                }
            }
        }
        
        for(i=0;i<len;i++){
            for(j=i;j<len;j++){
                if(ma[i][j]==1){ 
                    k = j-i;
                    if(max < k){ 
                        max = k;
                        i_index = i;
                        j_index = j;
                    }
                }
            }
            
        }

        for(i=i_index;i<=j_index;i++){
            ss += s[i];
        }
        //return ss;
        cp(ma,&len);

        cout<<ss<<endl;
        return 0;
}