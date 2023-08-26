class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs), [&](vector<int>& a, vector<int>& b){return a[1]<b[1];});
        int n= pairs.size(), len=1;
        int last= pairs[0][1];
        for(int ind=1;ind<n; ind++){
            if(pairs[ind][0]>last){
                len++;
                last= pairs[ind][1];
            }
        }
        return len;
    }
};