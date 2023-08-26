class Solution {
public:
    void dfs(int node, vector<vector<int>> adj, vector<int>& vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        // vector<int> adj[n];
        // for(int i=0; i<n;i++){
        //     for(auto it:rooms[i]) adj[i].push_back(it);
        // }
        vector<int> vis(n);
        dfs(0, rooms, vis);
        for(auto it:vis) if(!it) return false;
        return true;
    }
};