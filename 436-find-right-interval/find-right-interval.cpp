class Solution {
public:
    // int lb(int num , vector<pair<int,int>>& vec){
    //     int l=0, r=vec.size()-1;
    //     int pos=vec.size();
    //     while(l<=r){
    //         int mid= l +(r-l)/2;
    //         if(vec[mid].first>=num){
    //             r=mid-1;
    //             pos= vec[mid].second;
    //         }
    //         else l= mid+1;
    //     }
    //     return pos==n
    // }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> res;
        int n= intervals.size();
        // vector<pair<int,int>> vec;
        // for(int i=0;i<n;i++){
        //     vec.push_back({intervals[i][1], i});
        // }
        // sort(begin(vec), end(vec), [&](pair<int,int> & a, pair<int,int>& b){
        //     return a.first!=b.first?a.first<b.first:a.second<b.second;});
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[intervals[i][0]]=i;
        }
        for(int i=0;i<n;i++){
            auto pos= mp.lower_bound(intervals[i][1]);
            pos==mp.end()?res.push_back(-1):res.push_back(pos->second);
        }
        return res;
    }
};