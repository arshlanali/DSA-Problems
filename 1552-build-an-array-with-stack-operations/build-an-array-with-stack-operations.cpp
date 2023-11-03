class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cnt=1;
        vector<string> res;
        int sz= target.size();
        for(int i=0;i<sz;){
            res.push_back("Push");
            if(target[i]!=cnt){
                res.push_back("Pop");
            }
            else i++;
            cnt++;
        }
        return res;
    }
};