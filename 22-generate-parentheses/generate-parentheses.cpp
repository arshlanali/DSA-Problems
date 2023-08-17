class Solution {
public:
    void f(int open,int close,string output,vector<string> &res){
        if(open == 0 && close == 0){
            res.push_back(output);
            return;
        }
        if(open == close) f(open-1,close,output+'(',res);
        else if(open == 0) f(open,close-1,output+')',res);
        else{
            f(open-1,close,output+'(',res);
            f(open,close-1,output+')',res);
        }
    }

    vector<string> generateParenthesis(int n) {
        string output="";
        vector<string> res;
        f(n, n, output, res);
        return res;
    }
};