class Solution {
public:

    void find_left(int arr[], vector<int>& prices, int n){
        int min = prices[0];
        arr[0] = 0;
        for(int i=1;i<n;i++){
            if(min > prices[i]){
                min = prices[i];
            }
            arr[i] = (prices[i]-min)>arr[i-1]?(prices[i]-min):arr[i-1];
        }
    }
    void find_right(int arr[], vector<int>& prices, int n){
        int max = prices[n-1];
        arr[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            if(max < prices[i]){
                max = prices[i];
            }
            arr[i] = (max - prices[i])>arr[i+1]?(max - prices[i]):arr[i+1];
        }
    }

    int maxProfit(vector<int>& prices) {
        memset(arr_left, 0, 100000*sizeof(int));
        memset(arr_right, 0, 100000*sizeof(int));

        find_right(arr_right, prices, prices.size());
        find_left(arr_left, prices, prices.size());

        int opt = 0;
        int tmp;
        for(int i=0;i<n;i++) {
            tmp = arr_left[i] + arr_right[i];
            if(tmp > opt) opt = tmp;
        }
        return opt;
    }

    int arr_left[100000]; // record the opt val from the left hand side // sell
    int arr_right[100000] // record the opt val from the right hand side // buy
};