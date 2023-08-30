class Solution {
public:
int n;  
    int combinationSum4(vector<int>& nums, int K) {
        n= nums.size();
        vector<double> dp(K+1, 0);
        dp[0]=1;
        for(int target=1; target<=K; target++){
            for(int ind=0; ind<n; ind++){
                if(nums[ind]<=target) dp[target]+= dp[target-nums[ind]];
            }
        }
        return dp[K];
    }
};