class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int cx=queries[i][0];
            int cy= queries[i][1];
            int rad= queries[i][2];
            int cnt=0;
            for(auto it:points){
                double dist= sqrt( (cx-it[0])*(cx-it[0]) + (cy-it[1])*(cy-it[1]) );
                if(dist<=rad) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};