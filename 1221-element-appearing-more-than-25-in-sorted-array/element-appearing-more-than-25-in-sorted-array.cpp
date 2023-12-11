class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n= arr.size();
        for(int i=0;i<n;i++){
            int cnt=0;
            while(i+1<n && arr[i]==arr[i+1]){
                i++;
                cnt++;
            }
            if(cnt>=n/4) return arr[i];
        }
        return -1;
    }
};