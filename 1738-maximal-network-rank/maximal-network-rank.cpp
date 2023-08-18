class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n,vector<int>(n, 0));
        vector<int> degree(n,0);
        for(auto it: roads){
            degree[it[0]]++;
            degree[it[1]]++;
            adj[it[0]][it[1]]=1;
            adj[it[1]][it[0]]=1;
        }
        int maxrank=0;
        // for(int i=0;i<n;i++)  cout<< degree[i]<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<n && j!=i;j++){
                int rank= degree[i]+degree[j]- adj[i][j];
                maxrank= max(maxrank, rank);
            }
        }
        return maxrank;
    }
};