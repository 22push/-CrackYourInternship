class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        int j=0;
        int n=nums.size();
        int i=0;
        while(j<n){
            q.push({nums[j],j});
            if(j-i+1<k){
                j++;
            }
            else {
                while(!q.empty() && j-q.top().second+1>k)q.pop();
                ans.push_back(q.top().first);
                i++;
                j++;
            }
        }
        return ans;
    }
};