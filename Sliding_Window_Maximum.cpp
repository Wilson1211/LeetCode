#include <iostream>
#include <string.h>
#include <limits>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

// https://leetcode.com/problems/sliding-window-maximum/

int main() {
    int n, i, j, k;
    char a[200005];
    char strnum[10001];
    long nu;
    deque<int> mydeque;

    char *ptr1, *ptr2;
    //cin >>　n;
    cin.getline(a, 200005);
    int len = strlen(a);

    if(len==1){
        cin >> k;
        if(k == 1){
            cout<<a<<endl;
            return 0;
        }else{
            cout<<"none\n";
            return 0;
        }
    }


    vector<long> numv(len);

    ptr1 = a;
    ptr2 = strchr(ptr1, ' ');


    while(ptr2!=NULL){
        memcpy(strnum, ptr1, ptr2-ptr1);
        nu = stoi(strnum);
        numv.emplace_back(nu);
        ptr1 = ptr2+1;
        ptr2 = strchr(ptr1, ' ');
    }

    for(i=0;i<)


    return 0;
}