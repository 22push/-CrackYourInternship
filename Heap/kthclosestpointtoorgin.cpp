class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<k;i++){
            q.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
        }
        for(int i=k;i<points.size();i++){
            auto it =q.top();
            int val=it.first;
            if(points[i][0]*points[i][0]+points[i][1]*points[i][1]<val){
                q.pop();
                q.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            }
        }
        vector<vector<int>>ans(q.size());
        int i=0;
        auto it = q.top();
        cout<<it.first;
        while(!q.empty()){
            auto it = q.top();
            ans[i].push_back(it.second.first);
            ans[i].push_back(it.second.second);
            i++;
            q.pop();
        }
        return ans;
    }
};