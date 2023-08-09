class Solution {
public:
    bool isValid(vector<int>& nums, int p, int diff){
        int cnt=0;
        int i=0;
        int n= nums.size();
        while(i<n-1){
            if(nums[i+1]-nums[i]<=diff){
                cnt++;
                if(cnt==p) return true;
                i+=2;
            }
            else i++;
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int l=0, h= nums[n-1]-nums[0], res=0;
        while(l<=h){
            int mid= (l+h)/2;
            if(isValid(nums, p, mid)){
                res=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};