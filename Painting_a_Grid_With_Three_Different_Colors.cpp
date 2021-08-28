class Solution {
public:

    int GridColor(int m, int n, int i, int j, size_t cur, size_t prev) {
        if(i==m) {
            return GridColor(m, n, 0, j+1, 0, cur);
        }
        if(j==n){ // all done
            return 1;
        }

        if(i==0 && dp[j][prev]) {
            return dp[j][prev];
        }

        int k;
        int up = (i==0)?0:(cur>>((i-1)*2))&3;
        int left = (prev>>(i*2))&3;
        long res = 0;
        for(k=1;k<4;k++) {
            if(k!=up && k!=left) {
                res = (res + GridColor(m, n, i+1, j, cur+(k<<(i*2)), prev)) % 1000000007;
            }
        }

        if(i==0){
            dp[j][prev] = res;
        }
        return res;
    }

    int colorTheGrid(int m, int n) {
        size_t cur=0, prev=0;
        long res;
        memset(dp, 0, 1000*1024*sizeof(long));
        res = GridColor(m, n, 0, 0, 0, 0);
        return (int)res;
    }

    long dp[1000][1024];
};