#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;


void get_val(string &str1, string &str2, vector<ll>& num1, vector<ll>& num2, int& k) {
    
    int len1, len2;
    size_t ptr1, ptr2;
    

    string tmp;

    getline(cin, str1);
    len1 = str1.length();
    getline(cin, str2);
    len2 = str2.length();

    cin >> k;

    ptr1 = 0;
    ptr2 = str1.find_first_of(" ");
    while(ptr2 != string::npos) {
        tmp = str1.substr(ptr1, ptr2-ptr1);
        num1.emplace_back(stoi(tmp));
        ptr1 = ptr2+1;
        ptr2 = str1.find_first_of(" ", ptr1);
    }

    ptr2 = len1;
    tmp = str1.substr(ptr1, ptr2-ptr1);
    num1.emplace_back(stoi(tmp));


    ptr1 = 0;
    ptr2 = str2.find_first_of(" ");
    while(ptr2 != string::npos) {
        tmp = str2.substr(ptr1, ptr2-ptr1);
        num2.emplace_back(stoi(tmp));
        ptr1 = ptr2+1;
        ptr2 = str2.find_first_of(" ", ptr1);
    }

    ptr2 = len2;
    tmp = str2.substr(ptr1, ptr2-ptr1);
    num2.emplace_back(stoi(tmp));

}

struct A{
    int sum, x, y;
};
struct comparele {
    bool operator()(A& x, A& y) {
        return x.sum > y.sum;
    }
};

int main() {

    vector<ll> num1;
    vector<ll> num2;
    int len1, len2;
    int k;
    
    string str1, str2;

    
    get_val(str1, str2, num1, num2, k);

    len1 = num1.size();
    len2 = num2.size();

    vector<vector<int>> ans;
    priority_queue<A, vector<A>, comparele> qu;

    for(int i=0;i<len1;i++) {
        qu.emplace({num1[i]+num2[0], i, 0});
    }

    int i=1;
    while(k-- && qu.size()) {
        auto [sum, x, y] = qu.top();
        qu.pop();
        ans.emplace_back({num1[x], num2[y]});
        if(y+1<num2.size())qu.emplace({num1[x]+num2[y+1], x, y+1});
    }

    return 0;
}