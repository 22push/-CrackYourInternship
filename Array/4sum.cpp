class Solution {
public:
    void gettwosum(vector<int>& arr ,int i,long long sum,vector<vector<int>>&ans,int m){
        int k= arr[i-1];
        int j=arr.size()-1;
        map<pair<int,int>,int>mp;
        // vector<int>
        while(i<j){
            if(arr[i]+arr[j]==sum){
                if(mp.find({arr[i],arr[j]})==mp.end()){
                    vector<int>ar;
                    ar.push_back(m);
                    ar.push_back(k);
                    ar.push_back(arr[i]);
                    ar.push_back(arr[j]);
                    ans.push_back(ar);
                    ar.clear();
                    mp[{arr[i],arr[j]}]++;
                }
                i++;
                j--;
            }
            else if(arr[i]+arr[j]>sum){
                j--;
            }
            else{
                i++;
            }
        }
    }
    void threeSum(vector<int>& nums,long long target,int k,vector<vector<int>>&ans) {
        int m=nums[k-1];
        int n=nums.size();
        for(int i=k;i<n-2;i++){
            if( i>k && nums[i]==nums[i-1] ){
                continue;
            }
            gettwosum(nums,i+1,target-nums[i],ans,m);
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1] ){
                continue;
            }
            threeSum(nums,target-nums[i],i+1,ans);
        }
        return ans;
    }
};