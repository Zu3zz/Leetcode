class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> res(n+1,0);
        for(int i = n - 1; i>=0;i--){
            for(int j = 0; j<=i; j++){
                res[j] = min(res[j],res[j+1])+ triangle[i][j];
            }
        }
        return res[0];
    }
};