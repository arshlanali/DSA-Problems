class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(), piles.rend());
        int sum=0, n= piles.size();
        int j= n-1;
        for(int i=1;i<n && j>i;i+=2){
            sum+= piles[i];
            j--;
        }
        return sum;
    }
};