bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>degree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                degree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        int count =1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for (int j = 0; j < adj[it].size(); j++) {
                degree[adj[it][j]]--;
                if (degree[adj[it][j]] == 0) {
                    // q.mp(adj[it][j]);
                    q.push(adj[it][j]);
                    count++;
                }
            }
        }
        return count!=V;
    }