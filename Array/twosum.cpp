class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<int>arr;
        arr=nums;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        vector<int>ans;
        while(i<j){
            if(nums[i]+nums[j]==target){
                if(nums[i]==nums[j]){
                    // cout<<nums[i]<<nums[j];
                    for(int k=0;k<arr.size();k++){
                        if(nums[i]==arr[k]){
                            // cout<<k<<endl;
                            ans.push_back(k);
                        }
                    }
                    break;
                }
                ans.push_back(mp[nums[i]]);
                ans.push_back(mp[nums[j]]);
                break;
            }
            else if(nums[i]+nums[j]>target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};