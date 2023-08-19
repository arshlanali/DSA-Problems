class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n= temp.size();
        stack<int> st;
        vector<int> nextg(n,0);
        for(int i=n-1; i>=0; i--){
            while(st.size() && temp[st.top()]<=temp[i]) st.pop();
            if(st.size()) nextg[i]=st.top()-i;
            st.push(i);
        }
        return nextg;
    }
};