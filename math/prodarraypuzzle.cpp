vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here   
        long long prod=1;
        int z=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                prod*=nums[i];
            }
            else{
                z++;
            }
        }
        vector<long long int> ans;
        for(int i=0;i<n;i++){
            if(z>1){
                ans.push_back(0);
            }
            else if(z==1 && nums[i]==0){
                ans.push_back(prod);
            }
            else if(z==1 && nums[i]!=0){
                ans.push_back(0);
            }
            else{
                ans.push_back(prod/nums[i]);
            }
        }
        return ans;
    }