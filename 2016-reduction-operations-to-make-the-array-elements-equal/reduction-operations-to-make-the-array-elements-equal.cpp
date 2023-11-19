class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0, n= nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i]!=nums[i-1]) res+=n-i;
        }
        return res;
    }
};