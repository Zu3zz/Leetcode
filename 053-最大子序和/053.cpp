class Solution {
public:
    /*
    神奇的code 思路从动态规划实现
    具体解释可以从
    https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts/161348
    这种方法进行了空间上的优化
    */
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int var = 0;
        for(auto x: nums){
            var = max(x,var+x);
            res = max(res,var);
            //cout<<"x="<<x<<"var="<<var<<"res="<<res<<endl;
        }
        return res;
    }
};