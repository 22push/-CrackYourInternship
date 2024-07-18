 void getdfs(int v,vector<bool>&arr,vector<int> adj[],vector<int>&ans){
        arr[v]=true;
        ans.push_back(v);
        for(int i=0;i<adj[v].size();i++){
            if(arr[adj[v][i]]==false){
                getdfs(adj[v][i],arr,adj,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool>arr(V,false);
        vector<int>ans;
        // arr[0]=true;
        getdfs(0,arr,adj,ans);
        return ans;
    }