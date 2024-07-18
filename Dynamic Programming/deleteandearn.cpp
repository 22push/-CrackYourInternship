class Solution {
public:
    int getans(vector<int>&arr,int i,vector<int>&dp){
        if(i>=arr.size()){
            return 0;
        }
        else if(i==arr.size()-1){
            return dp[i]=arr[i];
        }
        else if(dp[i]!=-1){
            return dp[i];
        }
        else{
            return dp[i]= max(arr[i]+getans(arr,i+2,dp),getans(arr,i+1,dp));
        }
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>arr(10001,0);
        vector<int>dp(10001,-1);
        for(auto it:mp){
            arr[it.first]=it.first*it.second;
        }
        cout<<dp[0];
        return getans(arr,0,dp);
    }
};