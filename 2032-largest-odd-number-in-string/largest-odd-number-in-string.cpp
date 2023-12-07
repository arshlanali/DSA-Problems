class Solution {
public:
    string largestOddNumber(string num) {
        int n= num.size();
        string res;
        int pos=-1;
        for(int i=0;i<n; i++){
            int c= num[i]-'0';
            if(c&1) pos=i;
        }
        if(pos==-1) return res;
        for(int i=0;i<=pos;i++){
            res+=num[i];
        }
        return res;
    }
};