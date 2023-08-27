class Solution {
public:
    int n;
    unordered_map<int, int> mp;
    bool solve(vector<int>& stones, int ind, int jump, vector<vector<int>>& dp) {
        if(ind == n-1) return true;
        bool result = false;
        if(dp[ind][jump] != -1) return dp[ind][jump];
        for(int nextjump = jump-1; nextjump <= jump+1; nextjump++) {
            if(nextjump > 0) {
                int nextstone = stones[ind] + nextjump;
                if(mp.find(nextstone) != mp.end()) {
                    result |= solve(stones, mp[nextstone], nextjump, dp);
                }
            }
            
        }
        return dp[ind][jump] = result;
    }
    
    bool canCross(vector<int>& stones) { 
        if(stones[1] != 1) return false;
        n = stones.size();
        for(int i = 0; i<n; i++) {
            mp[stones[i]] = i;
        }
        vector<vector<int>> dp(2001, vector<int>(2001, -1));
        return solve(stones, 0, 0, dp);
    }
};