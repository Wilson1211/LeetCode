class Solution {
public:

    int paintcolor(int n, int i, int j, size_t cur, size_t prev) {
        if(j==3){
            paintcolor(n, i+1, 0, 0, cur);
        }

        if(i==n) {
            return 1;
        }

        if(j==0&&dp[i][prev]){
            return dp[i][prev];
        }
        
        int res, up, left;
        up = (prev>>(j*2))&3;
        left = (cur>>((j-1)*2))&3;

        for(int k=1;k<4;k++) {
            if(k!=up&&k!=left){
                res = (res + paintcolor(n, i, j+1, cur+(k<<(j*2)), prev)) % 1000000007;
            }
        }
        
        if(j==0){
            dp[i][prev] = res;
        }

    }

    int numOfWays(int n) {
        
        //init
        memset(dp, 0, sizeof(int)*5000*32);

        int res;
        res = paintcolor(n, 0, 0, 0, 0);
        return res;
    }

    int dp[5000][32];
};