class Solution {
public:
    int bestClosingTime(string customers) {
        int pen= 0, n= customers.size();
        for(auto it:customers) if(it=='Y') pen++;
        int minpen=pen;
        int minind=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y') pen--;
            else pen++;
            if(pen<minpen){
                minpen=pen;
                minind=i+1;
            }
        }
        return minind;
    }
};