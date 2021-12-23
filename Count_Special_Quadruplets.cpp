https://leetcode.com/problems/count-special-quadruplets/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
using namespace std;

#define maxn 10000
vector<int> nums = {1,1,1,3,5};

int main() {

    int res=0;

    int sz = nums.size();
    map<int, int> mm;
    mm[nums[sz-1]-nums[sz-2]] = 1;

    for(int b = sz-3;b>=1;b--){
        for(int a=0;a<b;a++){
            res += mm[nums[b]+nums[a]];
        }

        for(int c=b+1;c<sz;c++){
            mm[nums[c]-nums[b]]++;
        }
    }
    
    cout<<res<<endl;

    return 0;
}