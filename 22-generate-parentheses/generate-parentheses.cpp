class Solution {
public:
    // bool valid(string s){
    //     stack<char> st;
    //     for(int i=0; i<s.size();i++){
    //         if(s[i]=='('){
    //             st.push('(');
    //         }
    //         else{
    //             if(st.empty()){
    //                 return false;
    //             }
    //             else{
    //                 st.pop();
    //             }
    //         }
    //     }
    //     return true;
    // }

    void f(int open , int close, int n, vector<string>& res, string output, int ind){
        if(ind==2*n){
            res.push_back(output);
            return ;
        }
        if(open < n && ind<2*n-1){
            output+= '(';
            f(open+1, close, n, res, output, ind+1);
            output.pop_back();
        }
        if(close<open && ind>0){
            output+= ')';
            f(open, close+1, n, res, output, ind+1);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string output="";
        vector<string> res;
        f(0, 0, n, res, output, 0);
        return res;
    }
};