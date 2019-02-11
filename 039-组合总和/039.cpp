static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty()) return res;
        vector<int> tmp;
        dfs(candidates,res,tmp,target,0);
        return res;
    }
    void dfs(vector<int>& candidates,vector<vector<int>>& res, vector<int> tmp, int target, int start){
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        for(int i = start;i<candidates.size();i++){
            int n = candidates[i];
            if(target>=n){
                tmp.push_back(n);
                dfs(candidates,res,tmp,target-n,i);
                tmp.pop_back();
            }
        }
    }
};