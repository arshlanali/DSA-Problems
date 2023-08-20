class Solution {
public:
    vector<int> toposort(vector<int> adj[], vector<int> indegree){
        queue<int> q;
        int n= indegree.size();
        for(int i=0; i<n; i++) if(!indegree[i]) q.push(i);
        vector<int> topo;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        return topo.size()==n?topo:vector<int>();
    }
    vector<int> sortItems(int n, int m, vector<int>& grp, vector<vector<int>>& before) {
        for(int i=0; i<n; i++) if(grp[i]==-1) grp[i]=m++;
        vector<int> itemindegree(n);
        vector<int> adjitem[n];
        vector<int> grpindegree(m);
        vector<int> adjgrp[m];
        for(int i=0; i<n; i++){
            for(auto prev: before[i]){
                itemindegree[i]++;
                adjitem[prev].push_back(i);
                if(grp[i]!=grp[prev]){
                    adjgrp[grp[prev]].push_back(grp[i]);
                    grpindegree[grp[i]]++;
                }
            }
        }
        vector<int> itemtopo= toposort(adjitem, itemindegree);
        vector<int> grptopo= toposort(adjgrp, grpindegree);

        if(itemtopo.size()==0 || grptopo.size()==0) return {};
        
        vector<int> grptoitem[m];
        for(int i=0; i<itemtopo.size(); i++){
            int group= grp[itemtopo[i]];
            grptoitem[group].push_back(itemtopo[i]);
        }
         
        vector<int> res;
        for(int i=0; i<grptopo.size(); i++){
            int group= grptopo[i];
            res.insert(res.end(), grptoitem[group].begin(), grptoitem[group].end());
        }
        return res;

    }
};