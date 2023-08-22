class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while(n>0){
            n--;
            res+= (n%26)+65;
            n/=26;
            cout<<n<<endl;
        }
        reverse(res.begin(), res.end());
        return res;

    }
};