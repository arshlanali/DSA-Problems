class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1) return 5;
        vector<int> prev={5, 4, 3, 2, 1};
        int ans=15;
        for(int i=3;i<=n;i++){
            int temp=ans;
            ans=temp;
            vector<int> curr(5);
            curr[0]=temp;
            for(int j=1;j<5;j++){
                temp=temp-prev[j-1];
                ans+=temp;
                curr[j]=temp;
            }
            prev=curr;
        }
        return ans;
    }
};