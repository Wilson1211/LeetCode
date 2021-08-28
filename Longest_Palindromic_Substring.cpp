//https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include <string.h>
#include <limits>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;


int main () {
    string s = "";
    string manacher_str="#";
    int m_len;
    cin >> s;
    if(s.length() == 1) {
        cout<<s<<endl;
        return 0;
    }
    for(int i=0;i<s.length();i++) {
        manacher_str += s[i];
        manacher_str += "#";
    }

    m_len = manacher_str.length();

    int LPS_table[1001] = {};
    LPS_table[0] = 0;

    int center = 1;
    int maxlen = 0;
    int maxright = 0;
    int LPS_center = 1;
    
    for(int index = 1;index < m_len-1;index++) {
        if(index < maxright) {
            LPS_table[index] = min(LPS_table[2*center-index], maxright-index);
        }
        else{
            LPS_table[index] = 0;
        }

        while((index-LPS_table[index]-1)>=0 && (index + LPS_table[index]+1)<m_len && manacher_str[index-LPS_table[index]-1] == manacher_str[index+LPS_table[index]+1]) {
            LPS_table[index]++;
        }

        if(maxlen < LPS_table[index]) {
            maxlen = LPS_table[index];
            LPS_center = index;
        }

        if(index + LPS_table[index]-1 > maxright) {
            maxright = index+LPS_table[index];
            center = index;
        }
        
    }
    
    cout<<"out: ";
    if(LPS_center == 1) {
        cout<<s[0]<<endl;
        return 0;
    }
    for(int i=LPS_center-LPS_table[LPS_center]+1;i<LPS_center+LPS_table[LPS_center];i+=2) {
        cout<<manacher_str[i];
    }
    cout<<endl;

}



/*
"babad"
"cbbd"
"a"
"ac"
*/