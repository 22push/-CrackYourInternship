class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int j=1;
        int n=prices.size();
        int ans=0;
        int count=0;
        int last = prices[0];
        while(j<n){
            if(prices[j]>prices[i] && prices[j]>last){
                count=prices[j]-prices[i];
                last = prices[j];
                j++;
            }
            else{
                ans+=count;
                count=0;
                i=j;
                j++;
                last = prices[i];
            }
        }
        return ans+count;
    }
};