#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> nums;
    string str;
    getline(cin, str);

    stringstream stream;
    stream << str;

    int a[5001] = {};

    int n;
    int max=0, min=5000;
    while(stream>>n) {
        nums.emplace_back(n);
        a[n]++;
        if(n>max) max=n;
        if(n<min) min=n;
    }

    vector<int> ans(nums.size(), 0);

    int k;
    k = (nums.size()%2==1)?(nums.size()/2):((nums.size()-1)/2);
    int ptr1;

    int start;

    start = (nums.size()%2==1)?(nums.size()-2):(nums.size()-1);
    ptr1 = max;
    for(int i=1;i<nums.size();i+=2) {
        ans[i] = ptr1;
        a[ptr1]--;
        while(a[ptr1]<=0) ptr1--;
    }

    start = (nums.size()%2==1)?(nums.size()-1):(nums.size()-2);

    for(int i=0;i<nums.size();i+=2) {
        ans[i] = ptr1;
        a[ptr1]--;
        while(a[ptr1]<=0 && ptr1 >= min) ptr1--;
    }
    
    
    //int ptr1 = min, ptr2 = max;

    // while(ptr1<=ptr2) {
    //     ans.emplace_back(ptr1);
    //     a[ptr1]--;
    //     if(ptr1 == ptr2) break;
    //     while(a[ptr1]<=0 && ptr1 < ptr2) ptr1++;
    //     //if(ptr1>ptr2) break;
    //     ans.emplace_back(ptr2);
    //     a[ptr2]--;
    //     while(a[ptr2]<=0 && ptr2 >=ptr1) ptr2--;
    // }


    return 0;

}

/*
int main() {

    vector<int> num;

    string str;
    getline(cin, str);

    stringstream stream;
    stream << str;

    int n;
    while(stream>>n) {
        //cout<<n<<endl;
        num.emplace_back(n);
    }

    sort(num.begin(), num.end());

    vector<int> ans;
    int ptr1, ptr2;
    int cut = (num.size()+1)/2;
    ptr1 = 1; ptr2 = cut;

    int cnt = num.size()-ptr2;

    ans.emplace_back(num[0]);
    for(int i=1;i<=cnt;i++) {
        ans.emplace_back(num[ptr2++]);
        if(ptr1 < cut)ans.emplace_back(num[ptr1++]);
    }

    return 0;
}
*/