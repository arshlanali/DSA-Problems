class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int pairs=0;
        for(auto it:nums){
            if(hash[k-it]){
                pairs++;
                if(hash[k-it]==1) hash.erase(k-it);
                else hash[k-it]--;
            }
            else hash[it]++;
        }
        return pairs;
    }
};