/*
给你一个整数数组 nums，每次 操作 会从中选择一个元素并 将该元素的值减少 1。

如果符合下列情况之一，则数组 A 就是 锯齿数组：

每个偶数索引对应的元素都大于相邻的元素，即 A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即 A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组 nums 转换为锯齿数组所需的最小操作次数。
input: nums = [1,2,3] output: 2
input: nums = [9,6,1,6,2] output: 4
*/
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n=nums.size(),i,j,s=0,t=0;
        for(i=0;i<n;i+=2)
        {
            j=0;
            if(i)j=max(j,nums[i]-nums[i-1]+1);
            if(i+1<n)j=max(j,nums[i]-nums[i+1]+1);
            s+=j;
        }
        for(i=1;i<n;i+=2)
        {
            j=0;
            if(i)j=max(j,nums[i]-nums[i-1]+1);
            if(i+1<n)j=max(j,nums[i]-nums[i+1]+1);
            t+=j;
        }
        return min(s,t);
    }
};