//https://leetcode.com/problems/russian-doll-envelopes/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

#define maxn 5001

using namespace std;


pair<int, int> arr[maxn];
bool compele(vector<int> &s1, vector<int> &s2){
    return (s1[0] > s2[0]) || ((s1[0]==s2[0]) && (s1[1]<=s2[1]));
}

vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};

// return the last element index
int find_lowest_requirement(int index, int w, int h){
    int left=0, right=index;
    int i = (left+right)/2;
    int flag = 0;

    do{
        if(arr[i].first > w && arr[i].second > h){
            left = i;
            flag = 0;
        }else{
            right = i;
            flag = 1;
        }
        i = (left+right)/2;
    }while(i != left);

    if(flag){ 
        if(arr[i].first > w && arr[i].second > h){
            arr[i+1] = make_pair(w, h);
        }else{
            arr[i] = make_pair(w, h);
        }
    }else{// from the if statement i==right-1, replace the next item
        if(arr[right].first > w && arr[right].second > h){
            arr[right+1] = make_pair(w, h);
            if(index < right+1) index = right+1;
            //cout<<"right: "<<right<<" index: "<<index<< " w: "<<w<<" h: "<<h<<endl;
        }else{
            arr[i+1] = make_pair(w, h);
            if(index < i+1) index = i+1;
        }

    }
    return index;
}


int main() {

    vector<vector<int>> tmp = envelopes;
    sort(tmp.begin(), tmp.end(), compele);

    vector<int> *ptr;
    int sz = envelopes.size();
    
    arr[0] = make_pair(tmp[0][0], tmp[0][1]);

    int max_h = 0;
    int index = 0;

    for(int i=1;i<sz;i++){
        ptr = &(tmp[i]);
        index = find_lowest_requirement(index, (*ptr)[0], (*ptr)[1]);
        //cout<<"index: "<<index<<endl;
    }

    cout<<index+1<<endl;
    return 0;
}