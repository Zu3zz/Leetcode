class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        k = k%s;
        reverse(nums.begin(), nums.begin() + s - k);
        reverse(nums.begin()+s-k, nums.begin() + s);
        reverse(nums.begin(), nums.begin() + s);
    }
};