class Solution {
public:
    void BFS(vector<vector<int>>& image,int i,int j,int color,int l){
        queue<pair<int,int>>q;
        int n=image.size();
        int m=image[0].size();
        q.push({i,j});
        // dp[i][j]=true;
        image[i][j]=color;
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
                if(rnew>=0 && rnew<n && cnew>=0 && cnew<m && image[rnew][cnew]==l ){
                    q.push({rnew,cnew});
                    image[rnew][cnew]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color){
            return image;
        }
        BFS(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};