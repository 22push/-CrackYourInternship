class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        int n=nums1.size();
        int m=nums2.size();
        int dp[n][m];
        int ans =0;
        for(int i=0;i<n;i++){
            if(nums1[i]==nums2[0]){
                dp[i][0]=1;
                ans=1;
            }
            else{
                dp[i][0]=0;
            }
        }
        for(int i=0;i<m;i++){
            if(nums1[0]==nums2[i]){
                dp[0][i]=1;
                ans=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        // cout<<dp[0][2];
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(nums1[i]==nums2[j]){
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
};