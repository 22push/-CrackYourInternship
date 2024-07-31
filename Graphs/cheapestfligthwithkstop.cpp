class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>adj[n];
        for(auto it:flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>minprice(n,INT_MAX);
        minprice[src]=0;
        q.push({{0,src},0});
        int ans = INT_MAX;
        while(!q.empty()){
            auto it = q.front();
            int price = it.first.first;
            int cur = it.first.second;
            int curdis=it.second;
            q.pop();
            if(curdis>k){
                continue;
            }
            for(int i=0;i<adj[cur].size();i++){
                cout<<adj[cur][i][0]<<' ';
                if(price+adj[cur][i][1]<minprice[adj[cur][i][0]]){
                    q.push({{price+adj[cur][i][1],adj[cur][i][0]},curdis+1});
                    minprice[adj[cur][i][0]]=price+adj[cur][i][1];
                }
            }
        }
        return minprice[dst]==INT_MAX?-1:minprice[dst];
    }
};