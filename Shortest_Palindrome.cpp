#include <iostream>
#include <string.h>
#include <limits>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;


int main() {

    string s;
    int T;
    cin >> T;
    while(T--) {
        string manacher_str="#";
        cin >> s;
        if(!s.length()) cout<<""<<endl;
        
        for(int i=0;i<s.length();i++) {
            manacher_str+=s[i];
            manacher_str += "#";
        }
        int manalen=manacher_str.length();


        int lts_table[100002]={};

        int center=1;
        int lps_table[manalen]={};
        int maxright=0;
        
        for(int index = 1;index < manalen;index++) {
            if(index < maxright) {
                lps_table[index] = min(lps_table[2*center-index], maxright-index);
            }else{
                lps_table[index] = 0;
            }

            while((index-lps_table[index]-1)>=0 && (index+lps_table[index]+1)<manalen && manacher_str[index-lps_table[index]-1]==manacher_str[index+lps_table[index]+1]) {
                lps_table[index]++;
            }

            if(index + lps_table[index]-1 > maxright){
                maxright = index + lps_table[index]-1;
                center = index;
            }

        }

        int maxlen=0;
        int lps_center=0;

        for(int i=1;i<manalen;i++) {
            if(i-lps_table[i]==0) {
                lps_center = i;
            }
        }

        maxlen = lps_center + lps_table[lps_center];
        //cout<<"maxlen: "<<maxlen<<endl;
        string ans = "";
        for(int i=manalen-2;i>maxlen;i-=2) {
            ans += manacher_str[i];
        }
        ans += s;

        cout<<ans<<endl;
        
    
/*
        for(int i=1;i<s.length();i++) {
            int k = i;
            bool flag= 0;
            for(int j=0;j<k;j++){
                if(s[j] == s[k]){
                    k--;
                }else{
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                if(maxlen<i){
                    maxlen = i;
                }
            }
        }
        for(int i=s.length()-1;i>maxlen;i--) {
            cout<<s[i];
        }
        cout<<s<<endl;
        */
    }

    return 0;
}