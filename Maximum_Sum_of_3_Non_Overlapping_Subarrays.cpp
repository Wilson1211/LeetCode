#include <iostream>
#include <string.h>
#include <limits>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:

    void sol(vector<int>& nums, int k){
        int size = nums.size();
        int range_size = size-k;
        // calculate numk;
        for(int i=0;i<k;i++){
            numk[0] += nums[i];
        }
        for(int i=1;i<=size-k;i++){
            numk[i] = numk[i-1]-nums[i-1]+nums[i+k-1];
        }

        // initialize dp1&dp2&dp3
        for(int i=0;i<k;i++) {
            dp1[i] = numk[i];
            dp2[i] = numk[i];
            dp3[i] = numk[i];
            //index[i]=i;
        }

        // calculate dp1
        for(int i=k;i<=range_size;i++) {
            for(int j=k-1;(j>=0);j--){
                if(((i-k-j)>=0)&&(dp1[i]<dp1[i-k-j])){
                    dp1[i] = dp1[i-k-j];
                    //index[i] = index[i-k-j];
                }
            }
            if(dp1[i]<numk[i]){
                dp1[i] = numk[i];
                //index[i] = i;
            }
        }

        // calculate dp2 second range
        for(int i=k;i<=range_size;i++) {
            for(int j=k-1;(j>=0);j--){
                if(((i-k-j)>=0)&&(dp2[i]<dp2[i-k-j])){
                    dp2[i] = dp2[i-k-j];
                    //index[i] = index[i-k-j];
                }
            }
            for(int j=k-1;(j>=0);j--){
                if(((i-k-j)>=0)&&(dp2[i]<dp1[i-k-j]+numk[i])){
                    dp2[i] = dp1[i-k-j]+numk[i];
                    //index[i] = i-k-j;
                }
            }
        }

        // calculate dp3 second range
        for(int i=k;i<=range_size;i++) {
            for(int j=k-1;(j>=0);j--){
                if(((i-k-j)>=0)&&(dp3[i]<dp3[i-k-j])){
                    dp3[i] = dp3[i-k-j];
                    //index[i] = index[i-k-j];
                }
            }
            for(int j=k-1;(j>=0);j--){
                if(((i-k-j)>=0)&&(dp3[i]<dp2[i-k-j]+numk[i])){
                    dp3[i] = dp2[i-k-j]+numk[i];
                    //index[i] = i-k-j;
                }
            }
        }



    }


    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp1, 0, 20000*sizeof(long long));        
        memset(dp2, 0, 20000*sizeof(long long));        
        memset(dp3, 0, 20000*sizeof(long long));        
        memset(numk, 0, 20000*sizeof(long long));        
        //memset(index, 0, 20000*sizeof(int));

        sol(nums, k);

        vector<int> ans(3, 0);

/*
        // find ans
        int max=0;
        int max_id, sec_id, thr_id;
        //int j=2;
        for(int i=0;i<nums.size()-1;i++){
            if(max < dp3[i]){
                max = dp3[i];
                max_id = i;
            }
        }

        max = 0;
        for(int i=k;i>=0;i--){
            if(max < dp2[max_id-k-i]) {
                max = dp2[max_id-k-i];
                sec_id = max_id-k-i;
            }
        }

        max = 0;
        for(int i=k;i>=0;i--){
            if((sec_id-k-i>=0) && max < dp1[sec_id-k-i]) {
                max = dp1[sec_id-k-i];
                thr_id = sec_id-k-i;
            }
        }
*/
        int max = 0;
        int max_id, sec_id, thr_id;

        for(int i=0;i<nums.size();i++){
            if(max<dp3[i]){
                max = dp3[i];
                max_id = i;
            }
        }
        max=0;
        for(int i=0;i<max_id;i++){
            if(max<dp2[i]){
                max = dp2[i];
                sec_id = i;
            }
        }
                     
        max=0;
        for(int i=0;i<sec_id;i++){
            if(max<dp1[i]){
                max = dp1[i];
                thr_id = i;
            }
        }


        ans[2] = max_id;
        ans[1] = sec_id;
        ans[0] = thr_id;

        return ans;
    }
    long long numk[20000];
    long long dp1[20000];
    long long dp2[20000];
    long long dp3[20000];
    //int index[20000];
};

int main()
{
    Solution answer;
    vector<int> arr1 = {1,2,1,2,1,2,1,2,1};
    vector<int> arr2 = {1,2,1,2,6,7,5,1};
    vector<int> arr3 = {4,5,10,6,11,17,4,11,1,3};
    vector<int> arr4 = {18,11,14,7,16,4,18,11,4,8};

    int k1 , k2;
    k1 = k2 = 2;

    vector<int> ans;
    ans.resize(3, 0);
    
    ans = answer.maxSumOfThreeSubarrays(arr4, 2);

    ans = answer.maxSumOfThreeSubarrays(arr1, k1);
    //cout<<ans<<endl;
    ans = answer.maxSumOfThreeSubarrays(arr2, k2);
    //cout<<ans<<endl;
    ans = answer.maxSumOfThreeSubarrays(arr3, 1);

    /* code */
    return 0;
}
