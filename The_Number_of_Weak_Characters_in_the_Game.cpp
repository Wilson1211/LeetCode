//https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

#define maxn 5001

using namespace std;

vector<vector<int>> properties = {{7,7},{1,2},{9,7},{7,3},{3,10},{9,8},{8,10},{4,3},{1,5},{1,5}};

static bool compele(vector<int> &s1, vector<int> &s2) {
    return s1[0]>s2[0] || (s1[0]==s2[0])&&(s1[1]<=s2[1]);
}
int main() {
    vector<vector<int>> tmp = properties;
    int sz = properties.size();
    sort(tmp.begin(), tmp.end(), compele);
    
    int cnt = 0;
    int tar_at = tmp[0][0], tar_def = tmp[0][1];
    int pre_at = tmp[0][0], pre_def = tmp[0][1]; // greater than tar_at
    
    for(int i=1;i<sz;i++){
        if(tmp[i][1]<tar_def){
            if(tmp[i][0]<tar_at || tmp[i][1]<pre_def) cnt++;
            
        }else{
            if((i+1)<sz && (tmp[i+1][0] < tmp[i][0])){
                pre_at = tar_at;
                pre_def = tar_def;
            }
            tar_at = tmp[i][0]; tar_def = tmp[i][1];
        }
    }
    cout<<cnt<<endl;
    return 0;
}

