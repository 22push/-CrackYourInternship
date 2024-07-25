int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<bool>> arr( N , vector<bool> (N,false));
	    queue<pair<pair<int,int>,int>>q;
	    q.push({{KnightPos[0]-1,KnightPos[1]-1},0});
	    arr[KnightPos[0]-1][KnightPos[1]-1]=true;
	    int ans=INT_MAX;
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]){
	        return 0;
	    }
	    while(!q.empty()){
	        auto it = q.front();
            int ro = it.first.first;
            int co = it.first.second;
            int val = it.second;
            q.pop();
            int rmat[8]={2,2,-2,-2,1,1,-1,-1};
            int cmat[8] ={1,-1,1,-1,2,-2,2,-2};
            for(int i=0;i<8;i++){
                int rnew = ro+rmat[i];
                int cnew = co+cmat[i];
                if(rnew>=0 && rnew<N && cnew>=0 && cnew<N && arr[rnew][cnew]==false){
                    q.push({{rnew,cnew},val+1});
                    arr[rnew][cnew]=true;
                    if(rnew==TargetPos[0]-1 && cnew==TargetPos[1]-1){
                        ans= min(ans,val+1);
                    }
                }
            }
	    }
	    if(ans!=INT_MAX){
	        return ans;
	    }
	    else {
	        return -1;
	    }
	}