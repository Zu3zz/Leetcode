class Solution
{
public:
  int min3(int a, int b, int c)
  {
    int pos = a < b ? a : b;
    return c < pos ? c : pos;
  }
  int minDistance(string word1, string word2)
  {
    int n = word1.size();
    int m = word2.size();
    int dp[n + 1][m + 1] = {0};
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++)
      {
        if (i == 0 || j == 0)
        {
          dp[i][0] = i;
          dp[0][j] = j;
        }
        else
        {
          if (word1[i - 1] == word2[j - 1])
          {
            dp[i][j] = dp[i - 1][j - 1];
            continue;
          }
          dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
        }
      }
    return dp[n][m];
  }
};