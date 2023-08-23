class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int res=0;
        for(auto c:s){
            if(c=='(') st.push(c);
            else{
                if(st.size()) st.pop();
                else res++;
            }
        }
        return res+st.size();
    }
};