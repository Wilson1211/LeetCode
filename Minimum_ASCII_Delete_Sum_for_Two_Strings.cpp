//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> dp2;

vector<int> arr1, arr2;

int ss(char s1[], char s2[], int i, int j){

    int sz1 = strlen(s1);
    int sz2 = strlen(s2);

    if(dp2[i][j]!=-1) return dp2[i][j];
    if(i==0&&j==0){
        if(s1[0]!=s2[0]){
            dp2[0][0] = int(s1[0])+int(s2[0]);
        }else{
            dp2[0][0] = 0;
        }
    }else if(i==0||j==0){
        if(s1[i]!=s2[j]){
            if(i==0){
                dp2[i][j] = ss(s1, s2, i, j-1)+s2[j];
            }else{
                dp2[i][j] = ss(s1, s2, i-1, j)+s1[i];
            }
        }else{
            if(i==0) dp2[i][j] = arr2[j-1];
            else dp2[i][j] = arr1[i-1];
        }
    }

    if(dp2[i][j]== -1){
        if(s1[i]!=s2[j]){
            dp2[i][j] = min(ss(s1, s2, i-1, j)+s1[i], ss(s1, s2, i, j-1)+s2[j]);   
        }else{
            dp2[i][j] = ss(s1, s2, i-1, j-1);
        }
    }

    return dp2[i][j];
}

void minimumDeleteSum(char s1[], char s2[]) {

    int s1_sz = strlen(s1);
    int s2_sz = strlen(s2);
    int i, j, k;
    if(s1[0]!=s2[0]){
        dp[0][0] = int(s1[0])+int(s2[0]);
        //dp[0][0] = static_cast<int>(s1[0]);
    }
    for(i=1;i<s1_sz;i++) {
        if(s1[i]==s2[0]){
            dp[i][0] = arr1[i-1];
        }else{
            dp[i][0] = dp[i-1][0]+s1[i];
        }
    }
    for(i=1;i<s2_sz;i++) {
        if(s1[0]==s2[i]){
            dp[0][i] = arr2[i-1];
        }else{
            dp[0][i] = dp[0][i-1]+s2[i];
        }
    }
    for(i=1;i<s1_sz;i++){
        for(j=1;j<s2_sz;j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j]+(int)(s1[i]), dp[i][j-1]+(int)(s2[j]));
            }
        }
    }
}


int main() {

//    string a;
//    string b;
    string str1 = "delete";
    string str2 = "leet";

    int s1_sz = str1.length();
    int s2_sz = str2.length();
    char c1[s1_sz+1];
    char c2[s2_sz+1];

    dp = vector<vector<int>>(s1_sz+1, vector<int>(s2_sz+1, 0));
    dp2 = vector<vector<int>>(s1_sz+1, vector<int>(s2_sz+1, -1));
    strcpy(c1, str1.c_str());
    strcpy(c2, str2.c_str());

    arr1 = vector<int>(s1_sz);
    arr2 = vector<int>(s2_sz);
    arr1[0] = c1[0];arr2[0] = c2[0];

    for(int i=1;i<s1_sz;i++){
        arr1[i] = arr1[i-1]+c1[i];
    }
    for(int i=1;i<s2_sz;i++){
        arr2[i] = arr2[i-1]+c2[i];
    }

    minimumDeleteSum(c1, c2);
    cout<<dp[s1_sz-1][s2_sz-1]<<endl;
    
//    int tmp;
//    tmp = ss(c1, c2, s1_sz-1, s2_sz-1);

//    cout<<tmp<<endl;

    return 0;
}