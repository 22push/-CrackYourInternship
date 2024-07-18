class Solution {
public:
    int trap(vector<int>& height) {
        int slow =0;
        int fast=height.size()-1;
        int lowmax=0;
        int highmax=0;
        int ans=0;
        while(fast>=slow){
            if(height[slow]<=height[fast]){
                if(height[slow]>lowmax){
                    lowmax =height[slow];
                }
                else{
                    ans +=lowmax-height[slow];
                }
                slow++;
            }
            else {
                if(height[fast]>highmax){
                    highmax =height[fast];
                }
                else{
                    ans +=highmax-height[fast];
                }
                fast--;
            }
        }
        return ans;
    }
};