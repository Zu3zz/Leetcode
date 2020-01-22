class Solution {
  public int numIslands(char[][] grid) {
      if(grid == null || grid.length == 0){
          return 0;
      }
      int y = grid.length;
      int x = grid[0].length;
      int count = 0;
      for(int i = 0;i<y;i++){
          for(int j = 0;j<x;j++){
              if(grid[i][j] == '1'){
                  dfs(grid, i, j);
                  count ++;
              }
          }
      }
      return count;
  }
  public void dfs(char[][] grid, int y, int x){
      int ny = grid.length;
      int nx = grid[0].length;
      if(y < 0 || x < 0 || y >= ny || x >= nx || grid[y][x] == '0'){
          return;
      }
      grid[y][x] = '0';
      dfs(grid, y-1, x);
      dfs(grid, y+1, x);
      dfs(grid, y, x - 1);
      dfs(grid, y, x + 1);
  }
}