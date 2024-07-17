class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans=0;
        int n= matrix.size();
        int m= matrix[0].size();
        int dp[n][m];
        int ar=0;
        for(int i=0;i<n;i++){
            if(matrix[i][0]==49){
                dp[i][0]=1;
                ar=1;
            }
            else{
                dp[i][0]=0;
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[0][i]==49){
                dp[0][i]=1;
                ar=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==49){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                    // cout<<dp[i][j]<<endl;
                    ar=max(ar,dp[i][j]);
                    cout<<ar<<endl;
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return ar*ar;
    }
};