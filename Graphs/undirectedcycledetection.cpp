 bool dfs(int v,vector<int>adj[],vector<bool>&arr,int parent){
        arr[v]=true;
        for(int i=0;i<adj[v].size();i++){
            if(arr[adj[v][i]]==false){
                if(dfs(adj[v][i],adj,arr,v)==true){
                    return true;
                }
            }
            else if(adj[v][i]!=parent){
                return true;
            }
        }
        return false;
        
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>arr(V,false);
        for(int i=0;i<V;i++){
            if(arr[i]==false){
                if(dfs(i,adj,arr,-1)==true){
                    return true;
                }
            }
        }
        return false;
    }