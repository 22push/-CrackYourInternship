class Solution {
public:
    int coinChange(vector<int>& coins, int A) {
        int dp[A+1];
        for(int i=1;i<=A;i++){
            dp[i]=INT_MAX;
        }
        dp[0]=0;
        for(int i=1;i<=A;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j]){
                    int x = dp[i-coins[j]];
                    if(x!=INT_MAX && x+1<dp[i]){
                        dp[i]=x+1;
                    }
                }
            }
        }
        return dp[A]==INT_MAX ? -1: dp[A];
    }
};