class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0") return "0";
        int n= num1.size(), m= num2.size();
        vector<int> vec(n+m, 0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0; j--){
                vec[i+1+j]+= (num1[i]-'0')*(num2[j]-'0');
                vec[i+j]+= vec[i+1+j]/10;
                vec[i+1+j]= vec[i+1+j]%10;
            }
        }
        // for(int i=0;i<n+m;i++) cout<<vec[i]<<" ";
        string res="";
        int i=0;
        while(vec[i]==0) i++;
        for(;i<n+m;i++) res+=  vec[i]+'0';
        return res;
    }
};