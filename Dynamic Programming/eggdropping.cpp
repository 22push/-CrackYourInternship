
// ------------------------- in O(N*K) ------------------------

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        // int dp[k+1][n+1];
        int m=0;
        while (dp[m][k] < n) {
            m++;
            for (int x = 1; x <= k; x++) {
                dp[m][x] = 1 + dp[m - 1][x - 1] + dp[m - 1][x];
            }
        }
        return m;
    }
};

// ------------------------- in O(N*K*K) ------------------------
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,0));
        // int dp[k+1][n+1];
        for (int i = 0; i <= k; i++) {
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for(int i=1;i<=n;i++){
            dp[1][i]=i;
        }
        int res;
        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                dp[i][j]=INT_MAX;
                for(int x=1;x<=j;x++){
                    res = 1+max(dp[i-1][x-1],dp[i][j-x]);
                    dp[i][j]=min(res,dp[i][j]);
                }
            }
        }
        return dp[k][n];
    }
};