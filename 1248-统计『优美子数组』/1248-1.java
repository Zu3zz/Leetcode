class Solution {
  public int numberOfSubarrays(int[] nums, int k) {
      List<Integer> res = new ArrayList<Integer>(nums.length);
      int ans = 0;
      res.add(-1);
      for(int i = 0;i < nums.length;i++){
          if(nums[i] % 2 == 1){
              res.add(i);
          }
      }
      res.add(nums.length);
      for(int i=k; i<res.size()-1; i++) {
          int left = res.get(i-k+1) - res.get(i-k);//前缀区间数目
          int right = res.get(i+1) - res.get(i);//后缀区间数目
          ans += left * right;
      }
      return ans;
  }
}