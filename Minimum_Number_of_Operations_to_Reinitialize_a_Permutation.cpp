#include <iostream>
#include <string.h>
#include <limits>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, i, j, k;
    cin >> n;
    int a = 1;
    k = 0;
    do{
        if(a%2) {
            a = n/2 + a/2;
        }else{
            a = a/2;
        }

        k++;
    }while(a != 1);
    cout<<k<<endl;
}