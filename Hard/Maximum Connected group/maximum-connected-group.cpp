//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class disjointset{
public:
    vector<int> rank, parent, size;
    disjointset(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1,0);
        size.resize(n+1, 1);
        for(int i=1; i<=n ; i++) parent[i]=i;
    }
    int findpar(int node){
        if(node== parent[node]) return node;
        return parent[node]= findpar(parent[node]);
    }

    void unionbyrank(int u, int v){
        int pu= findpar(u);
        int pv= findpar(v);
        if(pu == pv) return; 
        if(rank[pu]> rank[pv]){
            parent[pv]=  pu;
        }
        else if(rank[pv]> rank[pu]){
            parent[pu]= pv;
        }
        else{
            parent[pv]= pu;
            rank[pu]++; 
        }
    }

    void unionbysize(int u, int v){
        int pu= findpar(u);
        int pv= findpar(v);
        if(pu == pv) return; 
        if(size[pu]> size[pv]){
            parent[pv]=  pu;
            size[pu]+= size[pv];
        }
        else if(rank[pv]>=rank[pu]){
            parent[pu]= pv;
            size[pv]+= size[pu];
        }
    }
};

class Solution {
public:
    bool isValid(int row, int col, int n){
        if(row>=0 && col>=0 && row<n && col<n) return true;
        return false;
    }
    int MaxConnection(vector<vector<int>>& grid) {
        int n= grid.size();
        disjointset ds(n*n);
        int delrow[]= {-1, 0, 1, 0}, delcol[]= {0, 1, 0, -1};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0) continue;
                for(int k=0; k<4; k++){
                    int nrow= i+delrow[k];
                    int ncol= j+ delcol[k];
                    int node= i*n+ j;
                    int adjnode= nrow*n+ ncol;
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]) ds.unionbysize(node, adjnode);
                }
            }
        }
        int res=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) continue;
                unordered_set<int> st;
                for(int k=0; k<4; k++){
                    int nrow= i+delrow[k];
                    int ncol= j+ delcol[k];
                    int node= i*n+ j;
                    int adjnode= nrow*n+ ncol;
                    if(isValid(nrow, ncol, n) && grid[nrow][ncol]) st.insert(ds.findpar(adjnode));
                }
                int sz=1;
                for(auto it:st) sz+= ds.size[it];
                res= max(res, sz);
            }
        }
        for(int i=0;i<n*n;i++) res= max(res, ds.size[ds.findpar(i)]);
        return res;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends