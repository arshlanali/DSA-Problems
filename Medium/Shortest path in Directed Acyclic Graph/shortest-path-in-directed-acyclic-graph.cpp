//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        minheap.push({0, 0});
        vector<int> dis(n, 1e9);
        dis[0]=0;
        while(minheap.size()){
            int node= minheap.top().second;
            int dist= minheap.top().first;
            minheap.pop();
            for(auto it:adj[node]){
                int adjnode= it.first;
                int edwt= it.second;
                if(edwt+dist<dis[adjnode]){
                    dis[adjnode]= edwt+ dist;
                    minheap.push({edwt+ dist,adjnode});
                }
            }
        }
        for(int i=0;i<n;i++) if(dis[i]==1e9) dis[i]=-1;
        return dis;
     }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends