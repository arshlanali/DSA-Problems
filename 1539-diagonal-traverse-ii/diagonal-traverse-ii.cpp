class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, stack<int>> hash;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int m= nums[i].size();
            for(int j=0;j<m;j++){
                hash[i+j].push(nums[i][j]);
            }
        }
        int dia=0;
        vector<int> res;
        while(hash.find(dia)!= hash.end()){
            stack<int> st= hash[dia];
            while(st.size()){
                res.push_back(st.top());
                st.pop();
            }
            dia++;
        }
        return res;
    }
};