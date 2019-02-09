class Solution {
    /*
    本solution使用改进的二分法 可以达到8ms的执行时间
    1.二分法
    2.牛顿迭代法 求点的切线来逼近根 公式如下Xn+1 = Xn - (F(Xn) / F'(Xn))
    由于要输出平方根  因为平方根肯定小于一般的右边界 所以可以将原本 right = x 修改为
    right = x / 2 + 1 这样可以节约一半的运行时间
    剩下的就是普通的二分法 根据平方根的大小情况 选择收缩左边界和右边界
    */
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        long left = 0;
        long right = x / 2 + 1;
        while(left <= right){
            auto midle = (left + right) / 2;
            auto sqrt = midle * midle;
            if(sqrt == x) return midle;
            else if (sqrt < x) left = midle + 1;
            else right = midle - 1;
        }
        return right;
    }
};