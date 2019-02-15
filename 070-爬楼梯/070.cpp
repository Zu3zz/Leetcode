class Solution {
public:
	// c++有时候会报错 很迷 是数组开的太大了吗
    int climbStairs(int n) {
        vector<int> res;
        res.push_back(0);
        res.push_back(1);
        res.push_back(2);
        for(int i =3;i<=n;i++){
            res.push_back(res[i-1] + res[i-2]);
        }
        return res[n];
    }
};