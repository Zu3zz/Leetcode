class Solution {
public:
	// 动态规划 核心递推公式就是
	// res[n] = res[1]*res[n-1] + res[2]*res[n-2] +.....+res[n-1]*res[1]
	// 即当根节点的值为n时 左儿子可以为从从1到n-1的所有情况 同时右儿子为n-1到1 只需要将两者相乘即可
    int numTrees(int n) {
        vector<int> res(n+1,0);
        res[0] = 1;
        res[1] = 1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                res[i] +=res[j-1]*res[i-j];
            }
        }
        return res[n];
    }
};