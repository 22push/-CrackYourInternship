long long getCount(int n) {
        // Your code goes here
        int arr[4][4]={{1,2,3,-1},{4,5,6,-1},{7,8,9,-1},{-1,0,-1,-1}};
        vector<pair<int,set<int>>>vec;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(arr[i][j]==-1){
                    continue;
                }
                else{
                    set<int>st;
                    int posx[]={1,-1,0,0,0};
                    int posy[]={0,0,1,-1,0};
                    for(int k=0;k<5;k++){
                        int curx = i+posx[k];
                        int cury=j+posy[k];
                        if(curx>=0 && curx<4 && cury>=0 && cury<4 && arr[curx][cury]!=-1){
                            st.insert(arr[curx][cury]);
                        }
                    }
                    vec.push_back({arr[i][j],st});
                    st.clear();
                }
            }
        }
        vector<vector<long long>>dp(n,vector<long long>(10,0));
        for(int i=0;i<10;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for (const auto& p : vec) {
                for (const int& elem : p.second) {
                    dp[i][elem]=(dp[i][elem]+dp[i-1][p.first]);
                }
            }
        }
        long long sum =0;
        for(int i=0;i<10;i++){
            sum+=dp[n-1][i];
            sum=sum;
        }
        return sum;
    }