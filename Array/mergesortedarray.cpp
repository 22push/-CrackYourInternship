class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l=0;
        int k=0;
        while(l<nums1.size()-n && k<n){
            if(nums1[l]>=nums2[k]){
                nums1.insert(nums1.begin() + l,nums2[k]);
                l++;
                k++;
            }
            else {
                l++;
            }
        }
       while(k<n){
         nums1.insert(nums1.begin() + nums1.size()-n ,nums2[k]);
         k++;
       }
       while(n>0){
        nums1.pop_back();
        n--;
       }
    }
};