class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ops=0;
        int n= nums.size();
        for(int i=n-2; i>=0 ; i--){
            if(nums[i] > nums[i+1]){
                int parts= nums[i]/nums[i+1];
                if(nums[i]%nums[i+1]) parts++;
                nums[i]= nums[i]/parts;
                ops+= parts-1;
            }
        }
        return ops;
    }
};