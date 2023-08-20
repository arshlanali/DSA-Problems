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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        disjointset ds(n);
        unordered_map<string,int> mp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j])==mp.end()) mp[accounts[i][j]]= i;
                else ds.unionbysize(i, mp[accounts[i][j]]);
            }
        }
        vector<string> ans[n];
        for(auto it: mp){
            string s= it.first;
            int node= ds.findpar(it.second);
            ans[node].push_back(s);
        }
        vector<vector<string>> res;
        for(int i=0; i<n; i++){
            if(ans[i].size()==0) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(ans[i].begin(), ans[i].end());
            for(auto it:ans[i]) temp.push_back(it);
            res.push_back(temp);
        }
        return res;
    }
};