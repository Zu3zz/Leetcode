"""
输出数组等于数组左边的乘积乘以右边的乘积
使用两次for循环
第一遍[0,n-1]用来保存当前数字左边的乘积 方法就是用k乘以当前数字
第二遍[n-1,0]用来保存当前数字右边的乘积 方法同上
两者相乘就是结果
"""
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)
        k = 1
        for i in range(len(nums)):
            res[i] = k
            k *= nums[i]
        k = 1
        for j in range(len(nums) - 1, -1,-1):
            res[j] *= k
            k *= nums[j]
        return res