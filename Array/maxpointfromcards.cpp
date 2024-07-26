class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>pre1(n);
        vector<int>pre2(n);
        pre1[0]=arr[0];
        pre2[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            pre1[i]=pre1[i-1]+arr[i];
        }
        for(int i=n-2;i>=0;i--){
            pre2[i]=pre2[i+1]+arr[i];
            // cout<<pre2[i]<<endl;
        }
        int ans = max(pre1[k-1],pre2[n-k]);
        int i=k-2;
        int j=n-1;
        while(i>=0){
            ans = max(ans,pre1[i]+pre2[j]);
            i--;
            j--;
        }
        return ans;
    }
};