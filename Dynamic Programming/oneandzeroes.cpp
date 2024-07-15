class Solution {
public:
    int maxsubset(vector<pair<int,int>>&vec,int m, int n,int i,vector<vector<vector<int>>>& dp){
        if(m<0 || n<0){
            return -1;
        }
        else if(i<0 || (m==0 && n==0)){
            return 0;
        }
        else if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        else{
            return dp[i][m][n]=max(1+maxsubset(vec,m-vec[i].first,n-vec[i].second,i-1,dp),maxsubset(vec,m,n,i-1,dp));
        }
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size=strs.size();
        vector<pair<int,int>>vec(size,{0,0});
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
               if(strs[i][j]==48){
                vec[i].first++;
               }
               else{
                vec[i].second++;
               }
            }
        }
        // for(int i=0;i<size;i++){
        //     cout<<vec[i].first<<" "<<vec[i].second<<endl;
        // }
        vector<vector<vector<int>>>dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return maxsubset(vec,m,n,size-1,dp);
    }
    
};