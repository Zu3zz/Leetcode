class Solution {
  public int dominantIndex(int[] nums) {
      int fir = 0,sec = 0,pos = 0;
      for (int i = 0;i<nums.length;i++){
          if(nums[i] > fir){
              sec = fir;
              fir = nums[i];
              pos = i;
          } else if(nums[i] < fir && nums[i] >= sec){
              sec = nums[i];
          }
      }
      if(fir >= 2 * sec){
          return pos;
      }else{
          return -1;
      }
  }
}