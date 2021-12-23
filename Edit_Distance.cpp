//https://leetcode.com/problems/edit-distance/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;


int h[500][500];


//string st1 = "dinitrophenylhydrazine";
//string st2 = "dimethylhydrazine";

//string st1 = "horse";
//string st2 = "ros";

string st1 = "intention";
string st2 = "execution";
void print_matrix(int a[][500], int b, int c){
    for(int i=0;i<b;i++){
        for(int j=0;j<c;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool comp(int a, int b){
    return a<=b;
}
int minDistance(string st1, string st2, int id1, int id2) {
    if(id1<0){
        return id2+1;
    }else if(id2<0){
        return id1+1;
    }


    if(h[id1][id2] != -1) return h[id1][id2];

    if(st1[id1]==st2[id2]){
        h[id1][id2] = min({minDistance(st1, st2, id1-1, id2-1), minDistance(st1, st2, id1-1, id2)+1, minDistance(st1, st2, id1, id2-1)+1}, comp);
    }else{
        h[id1][id2] = min({minDistance(st1, st2, id1-1, id2)+1, minDistance(st1, st2, id1, id2-1)+1, minDistance(st1, st2, id1-1, id2-1)+1}, comp);
    }
    
    return h[id1][id2];
}

void minD(string &st1, string &st2, int sz1, int sz2) {
    for(int i=1;i<sz1;i++) {
        for(int j=1;j<sz2;j++) {
            if(st1[i]==st2[j]){
                h[i][j] = min({h[i-1][j-1], h[i-1][j]+1, h[i][j-1]+1}, comp);
            }else{
                h[i][j] = min({h[i-1][j]+1, h[i][j-1]+1, h[i-1][j-1]+1}, comp);
            }
        }
    }
}

int main() {

    int sz1 = st1.length();
    int sz2 = st2.length();

    memset(h, -1, 500*500*sizeof(int));

    h[0][0] = (st1[0]==st2[0])?0:1;

    for(int i=1;i<sz2;i++){
        h[0][i] = (st1[0]==st2[i])?i:(h[0][i-1]+1);
    }
    for(int i=1;i<sz1;i++) {
        h[i][0] = (st1[i]==st2[0])?i:(h[i-1][0]+1);
    }

    //int tmp = minDistance(st1, st2, sz1-1, sz2-1);
    //cout<<"tmp: "<<tmp<<endl;
    minD(st1, st2, sz1, sz2);
    print_matrix(h, sz1,sz2);
    cout<<"ans: "<<h[sz1-1][sz2-1]<<endl;
    return 0;
}