#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int main(){
    int i, j=0, k, n;
    string s,ss;
    getline(cin,s);
    for(i=s.size()-1;i>=0;i--){
        if(s[i]==' '){
            ss = s.substr(i,s.size()-i+1);
            n = atoi(ss.c_str());
            ss = s.substr(0,i);
            //cout<<"str: "<<ss<<endl;
            break;
        }
    }
    if(n == 1){cout<<ss; return 0;}
    //cout<<"num: "<<n<<endl;
    vector<string> sv(min(int(ss.size()), n));
    bool change_dir = false;
    for(char c: ss){
        sv[j]+=c;
        if(j == 0 || j == n-1){
            change_dir = !change_dir;
        }
        j += change_dir?1:-1;
        //cout<<"c: "<<c<<" j: "<<j<<endl;
    }
    //cout<<sv[0]<<endl;
    for(string r:sv){
        cout<<r;
    }
    cout<<endl;

    return 0;
}