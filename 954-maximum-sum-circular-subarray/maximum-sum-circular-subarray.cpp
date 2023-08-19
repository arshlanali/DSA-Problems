class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum=0, maxsum=INT_MIN, minsum=INT_MAX, possum=0, negsum=0;
        for(auto it:nums){
            totalsum+= it;
            possum+= it;
            negsum+= it;
            maxsum= max(maxsum, possum);
            possum= possum<0?0:possum;
            minsum= min(minsum, negsum);
            negsum= negsum>0?0:negsum;
        }
        cout<<minsum<<" "<<totalsum<<" "<<maxsum;
        return minsum==totalsum?maxsum: max(totalsum-minsum, maxsum);
    }
};