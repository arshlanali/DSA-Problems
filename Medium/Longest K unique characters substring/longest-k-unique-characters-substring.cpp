//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i=0, j=0;
        unordered_map<char, int> hash;
        int n= s.size();
        int maxlen =-1;
        while(j<n){
            hash[s[j]]++;
            while(hash.size()>k){
                hash[s[i]]--;
                if(!hash[s[i]]) hash.erase(s[i]);
                i++;
            }
            if(hash.size()==k) maxlen= max(maxlen, j-i+1);
            j++;
        }
        return maxlen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends