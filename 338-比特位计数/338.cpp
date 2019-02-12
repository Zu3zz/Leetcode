class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1,0);
        for(int i= 1;i<=num;i++){
        		// res[0]的位置为0
        		// res[i]的值可以通过res[i&(i-1)] + 1 查找
        		// 原理如下 i&(i-1)通过位运算 可以将i转化为2进制 同时去除2进制串中最后一个1
        		// 如 6 = 1010 通过上面的运算 6->4(1010->1000)
        		// 由于要统计1的个数 6 一共有2个1 4一共有1个一 由于通过上面的位运算
        		// 将i的最后一个1消去 所以只要找到消去的元素的1的个数 在加一 即可
            res[i] += res[i&(i-1)] + 1;
        }
        return res;
    }
};