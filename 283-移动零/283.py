class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        point = 0
        for i in range(len(nums)):
            if nums[i]:
                nums[point],nums[i] = nums[i],nums[point]
                point+=1