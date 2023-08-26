class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n= nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1; i<n; i++){
            auto it= lower_bound(begin(lis), end(lis), nums[i]);
            if(it!=end(lis)) *it= nums[i];
            else lis.push_back(nums[i]);
            if(lis.size()>=3) return true;
        }
        return false;
    }
};