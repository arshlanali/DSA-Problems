class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& vis, unordered_map<int,int>& dis,int dist, int& len, vector<int>& extra, int i){
        vis[node]=1;
        extra[node]=i;
        dis[node]= dist;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, dis, dist+1, len, extra, i);
            }
            else if(extra[it]==i){
                len= max(len, dist- dis[it]+1);
            }
        }
        
    }
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        vector<int> adj[n];
        for(int i=0; i<n;i++){
            int it= edges[i];
            if(it!=-1) adj[i].push_back(it);
        }
        vector<int> vis(n+1), extra(n+1);
        int maxlen=-1;
        for(int i=0;i<n; i++)
        {
            if(!vis[i]){
                int len=0;
                unordered_map<int,int> dis;
                dfs(i,adj, vis, dis, 0, len, extra, i);
                maxlen= max(maxlen, len);
            }
        }
        cout<<maxlen<<" ";
        return maxlen<=1?-1:maxlen;
    }
};