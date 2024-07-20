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
};