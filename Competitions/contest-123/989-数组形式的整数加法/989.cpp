class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int len = A.size();
        int cur = K;
        vector<int> res;
        while(--len >= 0 || cur>0){
            if(len>=0){
                cur+=A[len];
            }
            res.push_back(cur % 10);
            cur /= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};