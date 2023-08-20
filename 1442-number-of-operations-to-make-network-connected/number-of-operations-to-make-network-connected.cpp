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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int extra=0;
        for(auto it:connections){
            if(ds.findpar(it[0])== ds.findpar(it[1])) extra++;
            else{
                ds.unionbysize(it[0], it[1]);
            }
        }
        int ncomp=0;
        for(int i=0; i<n;i++){
            if(ds.parent[i]==i) ncomp++;
        }
        if(extra<ncomp-1) return -1;
        return ncomp-1;
    }
};