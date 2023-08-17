class Solution {
public:
    // int f(int i, int j, vector<int> nums, vector<vector<int>>& dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int maxcoin=-1e9;
    //     for(int ind=i; ind<=j;ind++){
    //         int coin = f(i, ind-1, nums, dp) + nums[i-1]*nums[ind]*nums[j+1]+ f(ind+1, j, nums, dp);
    //         maxcoin=max(maxcoin, coin);
    //     }
    //     return dp[i][j]= maxcoin;
    // }
    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
        nums.push_back(1);
        nums.insert(begin(nums), 1);
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxcoin=-1e9;
                for(int ind=i; ind<=j;ind++){
                    int coin = dp[i][ind-1] + nums[i-1]*nums[ind]*nums[j+1]+ dp[ind+1][j];
                    maxcoin=max(maxcoin, coin);
                }
                dp[i][j]= maxcoin;
            }
        }
        return dp[1][n];
    }
};