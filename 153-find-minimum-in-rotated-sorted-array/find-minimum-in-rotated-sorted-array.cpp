class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int l=0, h=n-1;
        int mn= INT_MAX;
        while(l<=h){
            int mid= (l+h)/2;
            if(nums[l]<=nums[mid]){
                mn=min(mn, nums[l]);
                l=mid+1;
            }
            else{
                mn=min(mn, nums[mid]);
                h=mid-1;
            }
        }
        return mn;
    }
};