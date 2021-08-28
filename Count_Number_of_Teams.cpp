#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// https://leetcode.com/problems/count-number-of-teams/description/

vector<int> nums;
vector<int>ans;

int ans_count;

void pn(int ind, int place, int n, int dir) {
    for(int i=ind;i<n;i++) {
        if(place==1){
            ans.clear();
            ans.emplace_back(nums[i]);
            pn(i+1, 2, n, dir);
            ans.pop_back();
            //ans_down.emplace_back(nums[i]);
            //pn(++ind, 2, n);
            //ans_down.pop_back();
        }else if(place==2){
            if((nums[i]>ans[0]) && (dir == 1)){
                ans.emplace_back(nums[i]);
                pn(i+1, 3, n, dir);
                ans.pop_back();
            }else if((nums[i]<ans[0]) && (dir == -1)){
                ans.emplace_back(nums[i]);
                pn(i+1, 3, n, dir);
                ans.pop_back();
            }
        }else{
            if((dir == 1)&&(nums[i]>ans[1])){
                cout<<ans[0]<<" "<<ans[1]<<" "<<nums[i]<<endl;
                ans_count++;
            }else if((dir == -1)&&(nums[i]<ans[1])){
                cout<<ans[0]<<" "<<ans[1]<<" "<<nums[i]<<endl;
                ans_count++;
            }
        }
    }
}

int main() {
    int i, j, k;
    string line;

    getline(cin, line);
    istringstream iss(line);
    while(iss>>k){
        nums.emplace_back(k);
    }
    
    k = nums.size();
    ans_count = 0;

   // pn(0, 1, k, 1);
   // pn(0, 1, k, -1);

    //cout<<ans_count<<endl;

    for(i=0;i<n;i++){
        ans.emplace_back(nums[i]);
        for(j=i;j<)
    }

    return 0;

}