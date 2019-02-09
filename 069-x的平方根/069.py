class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        本solution执行时间72ms
        使用牛顿迭代法
        """
        if x<=1:
            return x
        r = x
        while r > x / r:
            r = (r + x/ r) // 2
        return int(r)