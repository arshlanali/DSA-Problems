class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        vector<int> adj[n], revadj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]); 
            indegree[it[1]]++;
            revadj[it[1]].push_back(it[0]);// reveresed adj;
        }
        vector<int> in(indegree.begin(), indegree.end());
        queue<int> q;
        for(int i=0; i<n; i++) if(!indegree[i])q.push(i);
        vector<int> topo;
        while(q.size()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        // for(auto it:topo) cout<<it<<" ";
        vector<vector<int>> res(n);
        for(auto node: topo){
            set<int> st;
            if(!in[node]) res[node]= vector<int>();
            else{
                for(auto it: revadj[node]){
                    st.insert(it);
                    if(res[it].size()){
                        st.insert(res[it].begin(), res[it].end());
                    }
                }
                vector<int> vec(st.begin(), st.end());
                res[node]=vec;
            }
        }
        return res;
    }
};