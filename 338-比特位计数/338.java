class Solution {
  public int[] countBits(int num) {
      int[] res = new int[num+1];
      res[0] = 0;
      if(num == 0) return res;
      res[1] = 1;
      for(int i = 2;i<=num;i*=2){
          int idx = i;
          for(int j = 0;j<i && idx <= num;j++){
              res[idx++] = res[j] + 1;
          }
      }
      return res;
  }
}