class Solution {
  public void moveZeroes(int[] nums) {
      if(nums == null || nums.length <= 1){
          return;
      }
      int index = 0;
      for(int i = 0;i<nums.length;i++){
          if(nums[i] != 0){
              nums[index] = nums[i];
              if(i != index){
                  nums[i] = 0;
              }
              index++;
          }
      }
  }
}