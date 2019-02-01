class Solution {
public:
	/*
	此solution执行时间比较慢 28ms 但是思路清晰简洁
	可以直接一遍循环至第k个元素 将所有前面的元素复制到后面 然后在使用erase函数去除
	过程如下 [1,2,3,4,5,6,7] -> [1,2,3,4,5,6,7,1]->[2,3,4,5,6,7,1]
	重复此过程 最后就会变成[5,6,7,1,2,3,4]顺利达到目的
	但是为什么执行时间会那么长 自己思考了一下原因 应该是因为本身是O(n)的时间复杂度
	push_back和erase也有一定的开销 所以比起189-1来 会花费多一些的时间
	*/
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums.empty() || (k %=n) == 0){
            return;
        }
        for(int i = 0;i<n-k;i++){
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};