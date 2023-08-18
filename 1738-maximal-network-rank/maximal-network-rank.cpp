class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        for(auto it: roads){
            degree[it[0]]+=1;
            degree[it[1]]+=1;
        }
        set<pair<int,int>> st;
        for(auto it:roads){
            st.insert({it[0], it[1]});
            st.insert({it[1], it[0]});
        }
        int maxrank=0;
        // for(int i=0;i<n;i++)  cout<< degree[i]<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<n && j!=i;j++){
                int rank= degree[i]+degree[j];
                if(st.find({i, j})!=st.end()) rank--;
                maxrank= max(maxrank, rank);
            }
        }
        return maxrank;
    }
};