//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


class Solution{
  public:
    string multiplyStrings(string s, string t) {
       int n= s.size(), m= t.size();
       int sneg=0, tneg=0;
       if(s[0]=='-') sneg^=1;
       if(t[0]=='-') tneg^=1;
       vector<int> vec(n+m);
       for(int i=n-1; i>=0; i--){
           for(int j=m-1; j>=0; j--){
               if(sneg && i==0) continue;
               if(tneg && j==0) continue;
                vec[i+j+1]+= (s[i]-'0')*(t[j]-'0');
                vec[i+j]+= vec[i+j+1]/10;
                vec[i+j+1]= vec[i+j+1]%10;
           }
       }
       
       int i=0;
       while(vec[i]==0) i++;
       string res="";
       if(sneg^tneg) res+='-';
       for(; i<n+m;i++) res+=vec[i]+'0';
       return res;
       
    }
};



//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends