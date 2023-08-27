class Solution {
public:
int n;
    void solve(int ind, vector<int> nums, vector<int> output, set<vector<int>>& st){
        if(ind==n){
            st.insert(output);
            return  ;
        }
        solve(ind+1, nums, output, st);
        output.push_back(nums[ind]);
        solve(ind+1, nums, output, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n= nums.size();
        sort(begin(nums), end(nums));
        set<vector<int>> st;
        vector<int> output;
        solve(0, nums, output, st);
        vector<vector<int>> res;
        for(auto it= st.begin(); it!=st.end();it++) res.push_back(*it);
        return res;
    }
};