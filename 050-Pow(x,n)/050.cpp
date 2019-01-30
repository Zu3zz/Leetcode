class Solution {
public:
	// 此solution执行时间为4ms 可以击败百分之100的回答
	// 一个皮一点的回答是可以直接return pow(x,n) 这样也可以直接拿到4ms的执行时间
	// 具体思路如下 运用递归的思想解决问题
	// 如果n是偶数 那么直接递归调用返回即可
	// 如果n是奇数 那么需要再多乘一个x本身
	// 有一个需要注意的坑就是如果n是负数且负数非常大 那么在n<0的时候回出现除以0的情况
	// 为了避免 需要将除操作放在power函数内部进行 不能直接这么写: 1.0 / power(x,-n)
    double power(double x, int n){
        if(n==0){
            return 1;
        }
        double half = power(x,n/2);
        if(n%2==0) return half*half;
        return x*half*half;
    }
    double myPow(double x, int n) {
        if(n<0){
            return power(1/x,-n);
        }
        return power(x,n);
    }
};