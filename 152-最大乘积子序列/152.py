class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a=[-float('inf') for _ in range(len(nums))]
        b=[-float('inf') for _ in range(len(nums))]
        if len(nums)==1:
            return nums[0]
        else:
            a[0]=nums[0]
            b[0]=nums[0]
            res=a[0]
            for i in range(1,len(nums)):
                a[i]=max(nums[i],max(nums[i]*a[i-1],nums[i]*b[i-1]))
                b[i]=min(nums[i],min(nums[i]*b[i-1],a[i-1]*nums[i]))
                res=max(a[i],res)
            return res