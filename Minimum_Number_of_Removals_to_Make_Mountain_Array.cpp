//https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

#define maxn 1001
using namespace std;


vector<int> nums={100,92,89,77,74,66,64,66,64};//{2,1,1,5,6,2,3,1} {4,3,2,1,1,2,3,1} {1,2,3,4,4,3,2,1};

long lleft[maxn];//from left
long rright[maxn];//from right

int main(){

    long id=0;
    int sz = nums.size();
    vector<long> lis(maxn, -1);
    vector<long>::iterator it;
    lis[0] = nums[0];
    lleft[0] = 0;
    rright[sz-1] = 0;
    for(int i=1;i<sz;i++){
        if(nums[i]>lis[id]){
            lis[++id] = nums[i];
            lleft[i] = id;
        }else{
            it = lower_bound(lis.begin(), lis.begin()+id+1, nums[i]);
            lleft[i] = it-lis.begin();
            *it = nums[i];
        }
    }

    lis.clear();
    lis.resize(maxn);
    lis[0] = nums[sz-1];
    id=0;
    for(int i=sz-2;i>=0;i--){
        if(nums[i]>lis[id]){
            lis[++id] = nums[i];
            rright[i] = id;
        }else{
            it = lower_bound(lis.begin(), lis.begin()+id+1, nums[i]);
            rright[i] = it-lis.begin();
            *it = nums[i];
        }
    }


    int max = 0;
    for(int i=1;i<sz-1;i++){
        if((lleft[i]!= 0 && rright[i] != 0) && (lleft[i]+rright[i]>max)) {
            max = lleft[i]+rright[i];
        }
    }

    cout<<sz - max-1<<endl;
    return 0;
}