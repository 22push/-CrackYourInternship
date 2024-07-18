class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;i++){
            int x = abs(nums[i]);
            if(nums[x]<0){
                return x;
            }
            nums[x]=-nums[x];
        }
        return len;
    }
};