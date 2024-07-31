class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0]=1;
        int p2=0;
        int p3=0,p5=0;
        for(int i=1;i<n;i++){
            int twomul = dp[p2]*2;
            int threemul = dp[p3]*3;
            int fivemul = dp[p5]*5;
            dp[i]=min(twomul,min(threemul,fivemul));
            if(dp[i]==twomul)p2++;
            if(dp[i]==threemul)p3++;
            if(dp[i]==fivemul)p5++;
        }
        return dp[n-1];
    }
};