#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;


void get_val(string &str1, string &str2, vector<ll>& num1, vector<ll>& num2) {
    
    int len1, len2;
    size_t ptr1, ptr2;
    
    int k;

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

class A {
    public:
        A(){};
        A(int a, int b){
            x = a;
            sum = b;
        };
        ~A(){};
        int x;
        int sum;
};

struct comp {

    bool operator() (const A& x, const A& y) {
        int sum1, sum2;
        sum1 = x.sum;
        sum2 = y.sum;
        return (sum1) <= (sum2);
    }

};

int main() {

    vector<ll> num1;
    vector<ll> num2;
    int len1, len2;
    
    string str1, str2;

    
    get_val(str1, str2, num1, num2);

    len1 = num1.size();
    len2 = num2.size();

    vector<A> ans;
    ll sum;
    for(int j=0;j<len2;j++) {
        for(int i=0;i<len1;i++) {
            sum = num1[i] + num2[j];
            ans.emplace_back(A(num1[i], sum));
        }
    }
    
    make_heap(ans.begin(), ans.end(), comp());

    while(ans.size()) {
        A tmp;
        tmp = ans.front();
        cout<<"["<<tmp.x<<", "<<tmp.sum-tmp.x<<"]\n";
        pop_heap(ans.begin(), ans.end(), comp()); ans.pop_back();
    }
    


    return 0;
}