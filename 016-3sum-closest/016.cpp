class Solution
{
public:
  int threeSumClosest(vector<int> &nums, int target)
  {

    sort(nums.begin(), nums.end());

    int res = nums[0] + nums[1] + nums[2];
    int n = nums.size();
    int diff = abs(res - target);

    for (int i = 0; i < n; i++)
    {
      int l = i + 1, r = n - 1;
      int t = target - nums[i];
      while (l < r)
      {
        if (nums[l] + nums[r] == t)
          return nums[i] + nums[l] + nums[r];
        else
        {
          if (abs(nums[l] + nums[r] - t) < diff)
          {
            diff = abs(nums[l] + nums[r] - t);
            res = nums[i] + nums[l] + nums[r];
          }
          if (nums[l] + nums[r] < t)
            l++;
          else
            r--;
        }
      }
    }
    return res;
  }
};