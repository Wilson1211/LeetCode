//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

vector<vector<int>> cuboids;

void sort_cu(vector<vector<int>>& cuboids){
    vector<vector<int>>::iterator it;
    int tmp;
    for(it=cuboids.begin();it<cuboid.end();it++) {
        if((*it)[0]<=(*it)[1]){
            if((*it)[2]<(*it)[0]){
                tmp = (*it)[2];
                (*it)[2] = (*it)[1];
                (*it)[1] = (*it)[0];
                (*it)[0] = tmp;
            }else{
                if((*it)[2]<(*it)[1]){
                    tmp = (*it)[2];
                    (*it)[2] = (*it)[1];
                    (*it)[1] = tmp;
                }
            }
        }else{
            if((*it)[2]<(*it)[1]){ // 2 1 0
                tmp = (*it)[2];
                (*it)[2] = (*it)[0];
                (*it)[0] = tmp;
            }else{ 
                if((*it)[2]<(*it)[0]){ // 1 2 0
                    tmp = (*it)[2];
                    (*it)[2]=(*it)[0];
                    (*it)[0] = (*it)[1];
                    (*it)[1] = tmp;
                }
            }
        }
    }
}

int main() {

    void sort_cu(cuboids);



    return 0;
}