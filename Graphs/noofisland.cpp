class Solution {
public:
    void BFS(vector<vector<char>>& grid,vector<vector<bool>>& dp,int i,int j){
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        q.push({i,j});
        dp[i][j]=true;
        while(!q.empty()){
            auto it = q.front();
            int ro = it.first;
            int co = it.second;
            q.pop();
            int rmat[4]={-1,0,1,0};
            int cmat[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int rnew = ro+rmat[i];
                int cnew = co+cmat[i];
                if(rnew>=0 && rnew<n && cnew>=0 && cnew<m && grid[rnew][cnew]=='1' && dp[rnew][cnew]==false){
                    q.push({rnew,cnew});
                    dp[rnew][cnew]=true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>dp(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && dp[i][j]==false){
                    count++;
                    BFS(grid,dp,i,j);
                }
            }
        }
        return count;
    }
};