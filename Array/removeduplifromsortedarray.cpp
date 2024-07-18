class Solution {
public:
    void swaptwo(vector<int>& nums, int i,int j){
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) {
        int low =0;
        int mid=0;
        int high = nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swaptwo(nums ,low,mid);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swaptwo(nums , mid,high);
                high--;
            }
        }
    }
};