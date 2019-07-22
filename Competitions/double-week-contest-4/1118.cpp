class Solution {
  // 一个月有多少天 水
public:
    const int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int numberOfDays(int Y, int M) {
        int ans = days[M-1];
        if((M==2 && Y%4==0 && Y%100!=0)||(Y%400 == 0)){
            ans++;
        }
        return ans;
    }
};