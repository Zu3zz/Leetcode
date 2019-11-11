class Solution {
  public void rotate(int[] nums, int k) {
      int n = nums.length;
      k %= n;
      reverse(nums, n-k,n-1);
      reverse(nums, 0,n-k-1);
      reverse(nums,0,n-1);
  }
  void reverse(int[]nums, int l, int r){
      while(l<r){
          int tmp = nums[l];
          nums[l] = nums[r];
          nums[r] = tmp;
          l++;
          r--;
      }
  }
}