	bool isBipartite(int V, vector<int> adj[]) {
        vector<int> arr(V, -1);
        int rev[2] = {1, 0};
        
        for (int start = 0; start < V; ++start) {
            if (arr[start] == -1) { 
                
                queue<pair<int, int>> q;
                q.push({start, 0});
                arr[start] = 0;
                
                while (!q.empty()) {
                    auto it = q.front();
                    q.pop();
                    int v = it.first;
                    int k = it.second;
                    
                    for (int i = 0; i < adj[v].size(); i++) {
                        if (arr[adj[v][i]] == -1) {
                            q.push({adj[v][i], rev[k]});
                            arr[adj[v][i]] = rev[k];
                        } else {
                            if (k == arr[adj[v][i]]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }