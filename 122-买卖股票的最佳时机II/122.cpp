class Solution {
public:
    /*
    此solution执行时间为4ms 快过百分之100的代码
    具体做法有以下几种
    1.DFS 对每天都有两种状态 买或者是卖股票 根据后一天的股票价格决定后一天的具体行动
    时间复杂度爆炸 会达到O(2^n)
    2.贪心 只需要循环一遍 分别比较后一天的股票价格与今天的价格 只要价格高 就买进然后第二天卖出
    因为当天可以无限次数买卖交易 所以可以这么做
    */
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int count = 0;
        for(int i =0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i]){
                count+=prices[i+1]-prices[i];
            }
        }
        return count;
    }
};