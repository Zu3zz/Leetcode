 /*
 * 给你一个 非递减 的正整数数组 nums 和整数 K，判断该数组是否可以被分成一个或几个 长度至少 为 K 的 不相交的递增子序列。
 * input: nums = [1,2,2,3,3,4,4], K = 3
 * output: true
 * input: nums = [5,6,6,7,8], K = 3
 * output: false
 * 思路： 只要找出数组里重复次数最多的元素 因为每一个需要被分的子序列中至少包含一个这个最多的元素L 所以只要count(L)个K能够大于数组长度就可以凑出来
 */

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
      int n =nums.size();
      // int count = 1;
      // int mid = nums[0];
      int max_count = 0, max_now = 0;
      for(int i = 0;i<n;i++){
        ++max_now;
        if(i==n-1 || nums[i] != nums[i+1]){
          max_count = max(max_count, max_now);
          max_now = 0;
        }
      }
      return (n/max_count)>=K;
    }
};