class Solution {
public:
    vector<string> mp= {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void perm(string digits, int ind,string& out, vector<string>& res){
        if(out.size()==digits.size()){
            res.push_back(out);
            return;
        }
        string temp= mp[digits[ind]-'2'];
        for(int i=0;i<temp.size();i++){
            out.push_back(temp[i]);
            perm(digits, ind+1, out, res);
            out.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size()==0) return res;
        string out="";
        perm(digits,0,out, res);
        return res;
    }
};