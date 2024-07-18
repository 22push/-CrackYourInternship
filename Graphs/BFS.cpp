 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool check[V];
        for(int i=1;i<V;i++){
            check[i]=false;
        }
        queue<int>q;
        vector<int>ans;
        check[0]=true;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++){
                if(check[adj[node][i]]==false){
                    check[adj[node][i]]=true;
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
    }