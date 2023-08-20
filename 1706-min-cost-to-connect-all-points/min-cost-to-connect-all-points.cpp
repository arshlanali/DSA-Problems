class disjointset{
    vector<int> rank, parent, size;
public:
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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<pair<pair<int,int>, int>> edges;
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n; j++){
                auto it= points[i], jt= points[j];
                if(it!=jt){
                    int wt= abs(it[0]-jt[0]) + abs(it[1]-jt[1]);
                    edges.push_back({{i, j}, wt});
                }
            }
        }
        sort(edges.begin(), edges.end(), [&](pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
            return a.second<b.second;
        });
        int mstwt=0;
        disjointset ds(n);
        for(auto it:edges){
            int u= it.first.first;
            int v= it.first.second;
            int wt= it.second;
            if(ds.findpar(u)!=ds.findpar(v)){
                mstwt+= wt;
                ds.unionbysize(u, v);
            }
        }
        return mstwt;
    }
};