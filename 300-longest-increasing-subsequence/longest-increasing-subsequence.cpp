class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> lis={nums[0]};
        for(int i=1;i<n;i++){
            auto it= lower_bound(begin(lis), end(lis), nums[i]);
            if(it!=lis.end()) *it=nums[i];
            else lis.push_back(nums[i]);
        }
        return lis.size();
    }
};