//https://leetcode.com/problems/shortest-palindrome/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std; 
#define maxn 50001

string s = "aacecaaa";
//string s = "abcabe";
//string s="abcabffabcabc";

int nnext[maxn];

void kmp_pre(const string &s) {
    int sz = s.length();
    cout<<"sz: "<<sz<<endl;
    int id_1=1;
    int id_s=0;
    nnext[0] = 0;
    while(id_1<sz){
        if(s[id_1] == s[id_s]){
            id_s++;
            nnext[id_1] = id_s;
            id_1++;
        }else if(id_s >0){
            id_s = nnext[id_s];
        }else{
            nnext[id_1] = 0;
            id_1++;
        }
    }
    cout<<"kmp: ";
    for(int i=0;i<sz;i++){
        cout<<nnext[i];
    }
    cout<<endl;
}


int main(){

    string ans="";
    string tmp;

    int sz = s.length();
    int start;
    tmp = s;
    tmp = s + string(tmp.rbegin(), tmp.rend());
    int t_sz = tmp.length();

    kmp_pre(s);
    //  cout<<"tmp: "<<tmp<<endl;
    int j=0;
    //arr[0] = -1;
    for(int i=sz;i<t_sz;i++) {
        if(tmp[i]==tmp[0]){
            start = i;
            int l = 1;
            int k = i+1;
            for(;k<tmp.length()&&tmp[k]==tmp[l++];k++){}
            if(k==tmp.length()){
                break;
            }
        }
    }

    for(int i=sz;i<start;i++){
        ans += tmp[i];
    }
    //cout<<"start: "<<start<<endl;
    ans += s;
    cout<<ans<<endl;
    //return ans;

}