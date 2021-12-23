//https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

#define pair<int, int> pp 

using namespace std;

bool compare(pp const &a, pp const &b) {
    return a.second <= b.second;
}

vector<int> nums={1,0,-1,0,-2,2};
int target = 0;

int main() {

    vector<vector<int>> ans;
    vector<vector<int>> index;
    
    vector<pair<int, int>> mm;
    for(int i=0;i<nums.size();i++){
        mm.emplace_back(make_pair(i, nums[i]));
    }

    sort(mm.begin(), mm.end(), compare);

    sort(nums.begin(), nums.end());

    int sz = nums.size();
    int i,j, k;
    for(int a=0;a<sz-3;a++){
        for(int b=a+1;b<sz-2;b++){
            int left, right, val;

            val = nums[a]+nums[b]+nums[left]+nums[right];

            while(nums[left]<nums[right]){
                if(val == target){
                    ans.emplace_back({nums[a], nums[b], nums[left], nums[right]});
                    index.emplace_back({a, b, left, right});
                }else if(val < target){
                    left++;
                }else{
                    right++;
                }
            }
        }
    }




    return 0;
}