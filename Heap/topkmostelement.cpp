
typedef pair<int, int> PII;
class Compare {
    public:
        bool operator()(PII below, PII above)
        {
            if (below.first < above.first) {
                return true;
            }
            else if (below.first == above.first
                    && below.second < above.second) {
                return true;
            }
    
            return false;
        }
    };
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>ump;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }
        priority_queue<PII, vector<PII>, Compare> ds;
        for(auto it:ump){
            ds.push({it.second,it.first});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(ds.top().second);
            ds.pop();
        }
        return ans;
    }
};