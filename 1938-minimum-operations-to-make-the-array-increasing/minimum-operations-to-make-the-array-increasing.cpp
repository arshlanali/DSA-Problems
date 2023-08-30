class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        int ops=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                ops+= nums[i-1]+1-nums[i];
                nums[i]=nums[i-1]+1;
            }
        }
        return ops;
    }
};