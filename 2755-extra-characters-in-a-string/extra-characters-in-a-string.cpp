class Solution {
public:
unordered_set<string> st;
int n;
    int solve(string s, int ind, vector<int>& dp) {
        if (ind >= n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        string currStr = "";
        int minextra = n;
        for (int i = ind; i < n; i++) {
            currStr+= s[i];
            int currextra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int nextextra = solve(s, i + 1, dp);
            minextra = min(minextra, currextra+ nextextra);
        }
        return dp[ind]=minextra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        for(auto it : dictionary) st.insert(it);
        vector<int> dp(n, -1);
        return solve(s, 0, dp);
    }
};