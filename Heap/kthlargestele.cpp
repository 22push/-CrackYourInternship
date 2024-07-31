class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it : mp){
            // cout<<it.first<<" "<<it.second<<endl;
            q.push({it.first,it.second});
        }
        while(k>=1){
            auto it = q.top();
            k=k-it.second;
            if(k<=0){
                return it.first;
            }
            q.pop();
        }
        return q.top().first;
    }
};