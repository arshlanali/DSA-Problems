class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int res = 0;
        int i = 0;
        long sum = 0;
        for(int j = 0; j<n; j++) {
            long target = nums[j];
            sum += nums[j];
            while((j-i+1)*target - sum > k) {
                sum -= nums[i];
                i++;
            }
            res = max(res, j-i+1);
        }

        return res;
    }
};

