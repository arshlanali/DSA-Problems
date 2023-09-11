class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n= groupSizes.size();
        vector<vector<int>> res;
        vector<vector<int>> mp(n+1);
        for(int i=0;i<n;i++){
            int sz=  groupSizes[i];
            mp[sz].push_back(i);
            if(mp[sz].size()==sz){
                res.push_back(mp[sz]);
                mp[sz]={};
            }
        }
        return res;
    }
};