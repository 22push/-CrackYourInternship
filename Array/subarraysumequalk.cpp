class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre[n];
        pre[0]=nums[0];
        unordered_map<int,int>mp;
        int ans=0;
        if(pre[0]==k)ans++;
        mp[0]++;
        mp[pre[0]]++;
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
            if(mp.find(pre[i]-k)!=mp.end()){
                ans+=mp[pre[i]-k];
            }
            mp[pre[i]]++;
        }
        return ans;

    }
};