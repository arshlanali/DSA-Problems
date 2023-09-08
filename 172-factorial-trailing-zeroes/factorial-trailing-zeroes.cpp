class Solution {
public:
    int trailingZeroes(int n) {
        vector<int> powerof5;
        powerof5.push_back(5);
        for(int i=2;i<=5;i++) powerof5.push_back(5*powerof5.back());
        int cnt=0;
        for(int i=0;i<5;i++) cnt+= n/powerof5[i];
        return cnt;
    }
};