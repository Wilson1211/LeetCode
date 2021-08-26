#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

//https://leetcode.com/problems/sliding-window-maximum/

// if use char array to store input and then convert it to int, it will be very large

int main() {

    int n, i, j, k;
    deque<long> mydeque;
    deque<long> myd_p;
    vector<long> num;
    vector<long> ans;
    long nu;

    string line;

/*
    while(cin>>nu){
        num.emplace_back(nu);
    }
*/

    getline(cin, line);
    istringstream iss(line);

    while(iss>>nu){
        num.emplace_back(nu);
    }
    n = num.size();

    cin >> k;

    for(i=0;i<k;i++) {

        while(mydeque.size()){
            nu = mydeque.back();
            if(nu > num[i]){
                break;
            }else{
                mydeque.pop_back();
                myd_p.pop_back();
            }
        }
       
        mydeque.emplace_back(num[i]);
        myd_p.emplace_back(i);
        
    }
    cout<<mydeque[0]<<" ";

    for(i=k;i<n;i++) {
        int len = mydeque.size();
        if(!len){
            mydeque.emplace_back(num[i]);
            myd_p.emplace_back(i);
        }else{
            if(myd_p[0]+k-1<i) {
                mydeque.pop_front();
                myd_p.pop_front();
            }
            
            while(mydeque.size()){
                nu = mydeque.back();
                if(nu > num[i]){
                    mydeque.emplace_back(num[i]);
                    myd_p.emplace_back(i);
                    break;
                }else{
                    mydeque.pop_back();
                    myd_p.pop_back();
                }
            }
            if(!mydeque.size()){
                mydeque.emplace_back(num[i]);
                myd_p.emplace_back(i);
            }
            
        }

        cout<<mydeque[0]<<" ";

    }
    cout<<endl;
    return 0;
}