class Solution {
public:
	/*
	此solution执行时间为4ms
	两个常量min和profit分别用来存放股票的最低价和能够赚取的最大利益
	直接一遍循环即可
	*/
    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int profit = 0;
        for(int i =0 ;i<prices.size();i++){
            if(prices[i]<min){
                min = prices[i];
            }
            if(prices[i]-min>profit){
                profit = prices[i]-min;
            }
        }
        return profit;
    }
};