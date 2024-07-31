/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int sum=0;
        int ans =0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum==0){
                ans=i+1;
            }
            else{
                if(mp.find(sum)==mp.end()){
                mp[sum]=i;
                }
                else{
                    ans = max(ans,i-mp[sum]);
                }
            }
        }
        return ans;
    }
};