class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        double prod =1;
        double ans=INT_MIN;
        for(int i=0;i<n;i++ ){
            if(prod<10e9){
                prod=prod*nums[i];
            }
            ans=max(ans,prod);
            if(nums[i]==0)prod=1;
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod*=nums[i];
            ans=max(ans,prod);
            if(nums[i]==0)prod=1;
        }
        return (int)ans;
    }
};