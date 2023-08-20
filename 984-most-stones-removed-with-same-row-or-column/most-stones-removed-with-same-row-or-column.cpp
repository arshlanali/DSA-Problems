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
    int removeStones(vector<vector<int>>& stones) {
        int sz= stones.size();
        int n= 0, m=0;
        for(auto it:stones){
            n=max(n, it[0]);
            m= max(m, it[1]);
        }
        disjointset ds(n+m+1);
        unordered_set<int> st;
        for(auto it: stones){
            int rownode= it[0];
            int colnode= it[1]+n+1;
            ds.unionbysize(rownode, colnode);
            st.insert(rownode);
            st.insert(colnode);
        }
        int ncomp=0;
        for(auto it:st){
            if(ds.findpar(it)==it) ncomp++;
        }
        return sz-ncomp;

    }
};