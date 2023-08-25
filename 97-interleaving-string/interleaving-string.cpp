class Solution {
public:
int n, m, N;
    bool solve(int i, int j, int k, string s1, string s2, string s3, unordered_map<string,bool>& dp){
        if(i==n && j==m && k==N) return true;
        if(k>=N) return false;
        string key= to_string(i) + "_" + to_string(j) + "_" + to_string(k);
        bool first=false, second=false;
        if(dp.find(key)!=dp.end()) return dp[key];
        if(s1[i] == s3[k]) first = solve(i+1, j, k+1, s1, s2, s3, dp);
        if(s2[j] == s3[k]) second = solve(i, j+1, k+1, s1, s2, s3, dp);
        return dp[key]= first|second;
    }
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string,bool> dp;
        n= s1.size(), m= s2.size(), N= s3.size();
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};
