class Solution {
public:
    string multiply(string s, string t) {
        int n= s.size(), m= t.size();
        if(s=="0" || t=="0")  return "0";
       int sneg=0, tneg=0;
       if(s[0]=='-'){
           sneg^=1;
           s= s.substr(1);
       } 
       if(t[0]=='-') {
           tneg^=1;
           t= t.substr(1);
       }
       vector<int> vec(n+m);
       for(int i=n-1; i>=0; i--){
           for(int j=m-1; j>=0; j--){
                vec[i+j+1]+= (s[i]-'0')*(t[j]-'0');
                vec[i+j]+= vec[i+j+1]/10;
                vec[i+j+1]= vec[i+j+1]%10;
           }
       }
       int i=0;
       while(i<n+m && vec[i]==0) i++;
       string res="";
       if(sneg^tneg) res+='-';
       for(; i<n+m;i++) res+=vec[i]+'0';
       return res;
    }
};