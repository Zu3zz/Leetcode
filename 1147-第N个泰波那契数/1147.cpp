class Solution {
public:
    int tribonacci(int n) {
        long long t[50];
        t[0] = 0;
        t[1] = t[2] = 1;
        for(int i = 3;i<=37;i++){
            t[i] = t[i-1] + t[i-2] + t[i-3];
        }
        return t[n];
    }
};