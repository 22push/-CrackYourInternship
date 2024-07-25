class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;
        int min =0;
        for(int i=1;i<prices.size();i++){
            if(prices[min]>prices[i]){
                min=i;
            }
            else {
                ans = max(ans,(prices[i]-prices[min]));
            }
        }
        return ans;
    }
};