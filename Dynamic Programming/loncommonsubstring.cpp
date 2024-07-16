int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int dp[n][m];
        int ans=0;
        for(int i=0;i<n;i++){
            if(S1[i]==S2[0]){
                dp[i][0]=1;
                ans=1;
            }
            else {
                dp[i][0]=0;
            }
        }
        for(int i=0;i<m;i++){
            if(S1[0]==S2[i]){
                dp[0][i]=1;
                ans=1;
            }
            else {
                dp[0][i]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(S1[i]==S2[j]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }