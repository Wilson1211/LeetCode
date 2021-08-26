#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    stringstream stream;
    string str;
    vector<int> n1;
    
    getline(cin, str);

    int K;
    cin >> K;

    stream << str;
    int n;
    while(stream >> n) {
        n1.emplace_back(n);
    }

    vector<int> revenue;
    int a[502]={}; // store max address
    int b[502] = {}; // store min address
    int dp[502][101][2]={}; // dp 0: revenue 1: min_ptr index


    int i= 0, k, pair=0;
    int min_ptr=0, max_ptr=0;
    int v_min=1000, v_max = 0;
    while(max_ptr < n1.size()-1) {
        while((min_ptr+1 < n1.size()) && n1[min_ptr]>=n1[min_ptr+1]) { min_ptr++; }
        if(min_ptr == n1.size()-1) break;
        b[pair]=min_ptr;
        max_ptr = min_ptr+1;
        while((max_ptr+1 < n1.size()) && (n1[max_ptr]<=n1[max_ptr+1])) { max_ptr++; }
        //revenue.emplace_back(n1[max_ptr]-n1[min_ptr]);
        a[pair++] = max_ptr;
        min_ptr = max_ptr;
    }

/*
    first initialize dp with k=1
*/

    for(i=1;i<=pair;i++) {
        int min_v=1000;
        int start=0;
        for(int j=0;j<=i;j++) {
            if(min_v > n1[b[j]]) {
                min_v=n1[b[j]];
                start = j;
            }
        }
        dp[1][i][0] = n1[a[i-1]]-n1[b[start]]; // store revenue
        dp[1][i][1] = start; // index of b
    }

/*
    end of dp with k=1
*/

    for(k=2;k<=K;k++) {
        dp[k][1][0] = dp[k-1][1][0];
        dp[k][1][1] = dp[k-1][1][1];
        for(i=2;i<=pair;i++) { // dp starts from 1 
            int min = 1000;
            int start;
            for(int j=1;j<i;j++) {
                if(min > n1[b[j]]) {
                    min = n1[b[j]];
                    start = j;
                }
            }
            dp[k][i][0] = n1[a[i-1]]-n1[b[start]];
            dp[k][i][1] = start; // index of b
        }
    }




    // for(i=1;i<=K;i++) {
    //     for(int j=0;j<pair;j++) {
    //         int min = 1000;
    //         for(k=0;k<=j;k++) {
    //             if(min > a[k]) min = a[k];
    //         }

    //     }
    // }

    // sort(revenue.begin(), revenue.end());
    // int j = revenue.size()-1;
    // int ans=0;
    // for(int i=0;i<k && j>=0;i++) {
    //     ans += revenue[j--];
    // }
    // cout<<ans<<endl;
    return 0;
}