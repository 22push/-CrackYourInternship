class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxi=0;
        int n= heights.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || heights[st.top()]>heights[i])){
                int height = heights[st.top()];
                st.pop();
                int w;
                if(st.empty())w=i;
                else{
                    w=i-st.top()-1;
                }
                maxi=max(maxi,height*w);
            }
            st.push(i);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();
        vector<int>arr(m,0);
        int maxi=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    arr[j]+=1;
                }
                else{
                    arr[j]=0;
                }
            }
            maxi = max(maxi,largestRectangleArea(arr));
        }
        return maxi;
    }
};