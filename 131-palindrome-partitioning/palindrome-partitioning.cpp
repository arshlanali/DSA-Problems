class Solution {
public:
bool isPalindrome(string s, int st, int e){
    while(st<=e){
        if(s[st++]!=s[e--]) return false;
    }
    return true;
}
void solve(int ind, string s, vector<string> output, vector<vector<string>>& res){
    if(ind==s.size()){
        res.push_back(output);
        return ;
    }
    for(int i=ind; i<s.size() ; i++){
        if(isPalindrome(s, ind, i)){
            output.push_back(s.substr(ind, i-ind+1));
            solve(i+1, s, output, res);
            output.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> output;
        solve(0, s, output, res);
        return res;
    }
};