//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        int mod=1e5;
        int n=  arr.size();
        queue<pair<int, int>> q;
        vector<int> dis(1e5, 1e9);
        q.push({start,0});
        while(q.size()){
            int node= q.front().first;
            int step= q.front().second;
            q.pop();
            for(int i=0;i< n;i++){
                int num= (node*arr[i])%mod;
                if(step+1< dis[num]){
                    dis[num]=step+1;
                    if(num==end) return step+1;
                    q.push({num, step+1});
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends