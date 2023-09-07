//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<int> q;
	    q.push(0);
	    vector<int> vis(V);
	    vis[0]=1;
	    if(X==0) return 0;
	    int level=0;
	    while(q.size()){
	        int sz= q.size();
	        level++;
	        for(int i=0;i<sz;i++){
	            int node= q.front();
	            q.pop();
	            for(auto it: adj[node]){
	                if(!vis[it]){
	                    vis[it]=1;
	                    q.push(it);
	                    if(it==X) return level;
	                }
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends