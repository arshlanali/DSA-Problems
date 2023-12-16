class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> hash;
        for(auto it: paths){
            hash[it[0]]++;
        }
        for(auto it:paths){
            if(hash[it[1]]==0) return it[1];
        }
        return "";
    }
};