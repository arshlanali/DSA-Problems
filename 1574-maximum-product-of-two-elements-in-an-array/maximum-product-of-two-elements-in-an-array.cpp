class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxi=0, smax=0;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi){
                smax= maxi;
                maxi=nums[i];
            }
            else if(nums[i]>smax && nums[i]<= maxi){
                smax= nums[i];
            }
        }
        cout<<maxi<<" "<<smax<<" ";
        return (maxi-1)*(smax-1);
    }
};