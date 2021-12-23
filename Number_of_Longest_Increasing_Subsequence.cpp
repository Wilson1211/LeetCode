//https://leetcode.com/problems/number-of-longest-increasing-subsequence/
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
#define maxn 2001
vector<int> nums = {1,2,4,3,5,4,7,2};//{1,3,5,4,7};//{1,2,4,3,5,4,7,2};

int main() {
    
    
    vector<int> arr;
    vector<int>::iterator it;

    int len[maxn];
    int cnt[maxn];// with arr[i] being end element, how many sequence 
 
    arr.emplace_back(nums[0]);
    len[0] = 1;cnt[0] = 1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]>arr[arr.size()-1]){
            arr.emplace_back(nums[i]);
            len[i] = arr.size();

        }else{
            it = (lower_bound(arr.begin(), arr.end(), nums[i]));
            *it = nums[i];
            len[i] = it-arr.begin()+1;
        }

        int tmp = 0;
        if(len[i]!=1){
            for(int j=0;j<i;j++){
                if((nums[i] > nums[j]) && len[j]==len[i]-1){
                    tmp += cnt[j];
                }
            }
            cnt[i] = tmp;
        }else{
            cnt[i] = 1;
        }
        
    }


    int ret = 0;
    int maxlen = 0;
    for(int i=0;i<nums.size();i++){
        if(maxlen < len[i]) {
            maxlen = len[i];
            ret = cnt[i];
        }else if(maxlen == len[i]){
            ret += cnt[i];
        }
    }

    cout<<ret<<endl;

    return 0;
}