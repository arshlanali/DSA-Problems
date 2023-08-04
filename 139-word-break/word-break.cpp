class Solution {
public:
    bool solve(int ind, string s,  unordered_set<string>& st, int n, vector<int>& dp){
        if(ind==n) return true;
        if(dp[ind]!=-1) return dp[ind];
        if(st.find(s)!=st.end()) return true;
        for(int l=1;l<=n;l++){
            string temp= s.substr(ind, l);
            if(st.find(temp)!=st.end() && solve(ind+l, s, st, n, dp)) {
                return dp[ind]=true;
            }
        }
        return dp[ind]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n= s.size();
        // string temp="";
        // string res="";
        // for(int i=0;i<n;i++){
        //     temp+=s[i];
        //     if(st.find(temp)!=st.end()){
        //         res+=  temp;
        //         temp="";
        //     }
        // }
        // cout<<res<<" ";
        // return res==s;
        vector<int> dp(301, -1);
        return solve(0, s,st, n, dp);
    }
};