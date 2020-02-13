public class Solution {
  public boolean findNumberIn2DArray(int[][] matrix, int target) {
      if(matrix == null || matrix.length == 0){
          return false;
      }
      int rows = matrix.length;
      int cols = matrix[0].length;
      // 从左下角开始查找
      int x = rows - 1;
      int y = 0;
      while (x >= 0) {
          while (y < cols && matrix[x][y] < target) {
              y++;
          }
          if (y < cols && matrix[x][y] == target) {
              return true;
          }
          x--;
      }
      return false;
  }
}