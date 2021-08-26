class Solution {
public:

    sol(vector<int>& nums, int k){
        int size = nums.size();
        int range_size = size-k;
        // calculate numk;
        for(int i=0;i<k;i++){
            numk[0] += nums[i];
        }
        for(int i=1;i<=size-k;i++){
            numk[i] = numk[i-1]-nums[i-1]+nums[i+k-1];
        }

        // calculate dp1
        for(int i=0;i<k;i++) {
            dp1[i] = numk[i];
        }

        for(int i=k;i<=range_size;i++) {
            for(int j=0;j<k&&((i-k-j)>=0);j++){
                if(dp1[i]<dp1[i-k-j]){
                    dp1[i] = dp1[i-k-j];
                }
            }
            if(dp1[i]<numk[i]){
                dp1[i] = numk[i];
            }
        }
        
        // calculate dp1 second range

        for(int i=k;i<=range_size;i++) {
            for(int j=0;j<k&&((i-k-j)>=0);j++){
                if(dp1[i]<dp1[i-k-j]+numk[i]){
                    dp1[i] = dp1[i-k-j]+numk[i];
                }
            }
            for(int j=0;j<k&&((i-k-j)>=0);j++){
                if(dp1[i]<dp1[i-k-j]){
                    dp1[i] = dp1[i-k-j];
                }
            }
        }

    }


    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(dp1, 0, 20000*sizeof(long long));        
        memset(dp2, 0, 20000*sizeof(long long));        
        memset(index, 0, 20000*sizeof(int));

    }
    long long numk[20000];
    long long dp1[20000];
    long long dp2[20000];
    int index[20000];
};