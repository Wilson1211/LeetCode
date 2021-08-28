class Solution {
public:

    int optval(int start, int end, vector<int>& prices) {
        int val=0;
        int min=MAX_INT, max=0;

        for(int i=start;i<=end;i++) {
            if(min>prices[i]){
                min = prices[i];
                max=0;
            }else if(max < prices[i]){
                max = prices[i];
                if(val < (max-min)){
                    val = max-min;
                }
            }
        }
        return val;
    }

    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int tmp, max;

        for(int i=0;i<len;i++) {
            tmp = optval(0, i, prices)+optval(i, len-1, prices);
            if(max < tmp){
                max = tmp;
            }
        }

    }
};