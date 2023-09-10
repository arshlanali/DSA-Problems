class Solution {
public:
    int minFlips(int a, int b, int c) {
      int cnt = 0;
      for(int i = 0; i < 32; i++){
         int bitc = (c >> i)&1;
         int bita = (a >> i)&1;
         int bitb = (b >> i)&1;
         if((bita || bitb) != bitc){
            if(!bitc){
               if(bita == 1 && bitb == 1) cnt+= 2;
               else cnt++;
            }
            else cnt++;
         }
      }
      return cnt;
    }
};