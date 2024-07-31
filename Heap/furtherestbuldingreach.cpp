class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>>q;
        int i=0;
        q.push(INT_MAX);
        for(i=1;i<heights.size();i++){
            if(heights[i]>heights[i-1]){
                if(ladders>0){
                    q.push(heights[i]-heights[i-1]);
                    ladders--;
                }
                else{
                    auto it = q.top();
                    int l=heights[i]-heights[i-1];
                    if(it>=l && bricks>=l){
                        bricks-=l;
                    }
                    else if(it>=l && bricks<l){
                        return i-1;
                    }
                    else if(it<l && bricks>=it){
                        bricks-=it;
                        q.pop();
                        q.push(l);
                    }
                    else{
                        return i-1;
                    }
                }
            }
        }
        return i-1;
    }
};