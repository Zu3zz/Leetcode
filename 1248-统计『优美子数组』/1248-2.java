class Solution {
  public int numberOfSubarrays(int[] nums, int k) {
      int[] res = new int[nums.length + 1];
      res[0] = 1;
      int tmp = 0;
      for(int num: nums){
          tmp += num & 1;
          res[tmp] += 1;
      }
      int r = 0;
      for(int i = 0;i<=nums.length-k;i++){
          r += res[i] * res[i+k];
      }
      return r;
  }
}