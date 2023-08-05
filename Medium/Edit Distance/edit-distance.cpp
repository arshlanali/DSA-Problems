//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int n= s.size(), m= t.size();
        vector<int> prev(m+1,0), curr(m+1, 0);
        for(int i=0;i<=m;i++) prev[i]=i;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                else{
                    curr[j]= 1+min(prev[j-1], min(curr[j-1], prev[j]));
                }
            }
            prev= curr;
        }
        return prev[m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends