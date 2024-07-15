class Solution {
public:
    int climbs(int n,vector<int>& dp){
        if(dp[n]!=-1){
            return dp[n];
        }
        if(n<=0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else{
            return dp[n]=climbs(n-1,dp)+climbs(n-2,dp);
        }
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climbs(n,dp);
    }
};