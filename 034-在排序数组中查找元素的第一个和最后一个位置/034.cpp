static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        if(nums.size() == 0) return {-1,-1};
        for(int i=0;i<nums.size();i++){
            if(target == nums[i]){
                res[0] = i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(target == nums[i]){
                res[1] = i;
                break;
            } 
        }
        return res;
    }
};