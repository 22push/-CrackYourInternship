vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>degree(V,0);
	    vector<bool>arr(V,false);
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            degree[adj[i][j]]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(degree[i]==0){
	            q.push(i);
	            arr[i]=true;
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        auto it = q.front();
	        ans.push_back(it);
	        q.pop();
	       // degree[it]--;
	        for (int j = 0; j < adj[it].size(); j++) {
                degree[adj[it][j]]--;
                if (degree[adj[it][j]] == 0) {
                    q.push(adj[it][j]);
                }
            }
	    }
	    return ans;
	}