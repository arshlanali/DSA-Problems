class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> hash;
        int cnt=0;
        for(auto it:paths){
            if(!hash[it[0]]) hash[it[0]]=cnt++;
            if(!hash[it[1]]) hash[it[1]]= cnt++;
        }
        // for(auto it:hash){
        //     cout<<it.first<<" "<<it.second<<" ";
        // }
        int n= hash.size();
        // cout<<n<<" ";
        vector<int> outdegree(n+1);
        for(auto it:paths){
            outdegree[hash[it[0]]]++;
        }
        int res=-1;
        for(int i=1;i<=n;i++){
            // cout<<outdegree[i]<<" ";
            if(outdegree[i]==0){
                res=i;
                break;
            }
        }
        for(auto it:hash){
            if(it.second==res) return it.first;
        }
        return "";
    }
};