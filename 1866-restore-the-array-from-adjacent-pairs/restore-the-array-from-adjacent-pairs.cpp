class Solution {
    vector<int> res;
public:
    void dfs(int u, int prev, unordered_map<int,vector<int>>& adj){
        res.push_back(u);
        for(auto v: adj[u]){
            if(v!=prev){
                dfs(v, u, adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n= adjacentPairs.size()+1;
        unordered_map<int,vector<int>> adj;
        for(auto it: adjacentPairs){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int start=-1;
        for(auto it: adj){
            if(it.second.size()==1){
                 start=it.first;
                 break;
            }
        }
        dfs(start, -1, adj);
        return res;
    }
};