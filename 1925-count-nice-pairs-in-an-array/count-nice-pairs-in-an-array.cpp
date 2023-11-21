class Solution {
public:
int rev(int a){
    if(!a) return a;
    string s= to_string(a);
    reverse(s.begin(), s.end());
    int res= stoi(s);
    return res;
}
    long long countNicePairs(vector<int>& nums) {
        long long res=0;
        long long mod= 1e9+7;
        int n= nums.size();
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++){
            int toFind= nums[i]-rev(nums[i]);
            if(hash.find(toFind)!=hash.end()){
                res = (res+hash[toFind])%mod;
            }
            hash[toFind]++;
        }
        return res;
    }
};