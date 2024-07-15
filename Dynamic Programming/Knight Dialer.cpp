class Solution {
public:
    int knightDialer(int n) {
        int arr[4][4] = {{1,2,3,-1},{4,5,6,-1},{7,8,9,-1},{-1,0,-1,-1}};
        vector<pair<int,set<int>>>vec;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                set<int>st;
                if(arr[i][j]==-1){
                    continue;
                }
                int upx[]={2,2,1,1,-1,-1,-2,-2};
                int upy[] ={1,-1,2,-2,2,-2,1,-1};
                for(int k=0;k<8;k++){
                    int curx=i+upx[k];
                    int cury = j+upy[k];
                    if(curx<4 && curx>=0 && cury>=0 && cury<4 && arr[curx][cury]!=-1){
                        st.insert(arr[curx][cury]);
                        // cout<<arr[curx][cury]<<" ";
                    }
                }
                vec.push_back({arr[i][j],st});
                st.clear();
                // cout<<endl;
            }
        }
        vector<vector<int>>dp(n,vector<int>(10,0));
        for(int i=0;i<10;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for (const auto& p : vec) {
                // cout << "First: " << p.first << ", Second: ";
                // dp[i][p.first]=
                for (const int& elem : p.second) {
                    // cout << elem << " ";
                    dp[i][elem]=(dp[i][elem]+dp[i-1][p.first])%1000000007;
                }
                // std::cout << std::endl;
            }
        }
        int sum =0;
        for(int i=0;i<10;i++){
            sum+=dp[n-1][i];
            sum=sum%1000000007;
        }
        return sum;
    }
};