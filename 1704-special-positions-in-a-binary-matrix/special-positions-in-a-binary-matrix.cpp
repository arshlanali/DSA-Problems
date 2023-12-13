class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        set<pair<int,int>> row;
        int n= mat.size(), m= mat[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            int cnt=0;
            pair<int,int> p;
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    cnt++;
                    p.first= i;
                    p.second=j;
                }
            }
            if(cnt==1) row.insert({p});
        }
        // for(auto it: row) cout<<it<<" ";
        for(int j=0;j<m;j++){
            int cnt=0;
            pair<int,int> p;
            for(int i=0;i<n;i++){
                if(mat[i][j]){
                    cnt++;
                    p.first= i;
                    p.second=j;
                }
            }
            if(cnt==1){
                // cout<<j<<" ";
                if(row.find({p})!=row.end()) res++;
            }
        }
        return res;
    }
};