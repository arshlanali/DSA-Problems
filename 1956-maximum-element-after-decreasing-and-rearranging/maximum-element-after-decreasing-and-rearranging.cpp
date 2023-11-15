class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n= arr.size();
        sort(arr.begin(),arr.end());
        int maxi=0;
        for(int i=0;i<n;i++){
            if(i==0) arr[i]=1;
            else if(abs(arr[i]-arr[i-1])>1) arr[i]= arr[i-1]+1;
            maxi= max(maxi, arr[i]);
        }
        return maxi;
    }
};