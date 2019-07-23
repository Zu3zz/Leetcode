class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> fico(n, 1);
        for(int i = 1; i<n;i++) fico[i] = fico[i-1] * i;
        k-=1;
         for (int i = n; i >= 1; --i) {
            int j = k / fico[i - 1];
            k %= fico[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};