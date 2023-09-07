class Solution {
    int n;
public:
    int pal(string s,  int left, int right){
        while(left>=0 && right<n && s[left]==s[right]) left--, right++;
        return right-left-1;
    }
    string longestPalindrome(string s) {
        n= s.size();
        int start=n, maxlen=0;
        for(int i=0; i<n;i++){
            int oddlen= pal(s, i, i);
            int evenlen= pal(s, i, i+1);
            int len= max(oddlen, evenlen);
            if(len>maxlen){
                maxlen= len;
                start= i-(len-1)/2;
            }
        }
        return s.substr(start, maxlen);
    }
};