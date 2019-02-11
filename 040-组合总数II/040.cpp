static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
// 大题思路与039相同 在排序前需要先对candidates数组进行一次排序 因为所给数组是乱序的
// 另外由于存在重复的元素 为了避免元素之间选择的重复 dfs的过程中 数组的起始位置需要根据后一个数字是否与前一个数字相同 进行增加
class Solution {
public:
	/*
		12ms执行时间
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set <vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,res,tmp,target,0);
        return vector<vector<int>> (res.begin(),res.end());
    }
    void dfs(vector<int>& candidates,set<vector<int>>& res, vector<int> tmp, int target, int start){
        if(target<0) return;
        if(target == 0){
            res.insert(tmp);
            return;
        }
        for(int i = start;i<candidates.size();i++){
            int n = candidates[i];
            if(target>=n){
                tmp.push_back(n);
                dfs(candidates,res,tmp,target-n,i+1);
                tmp.pop_back();
            }
        }
    }
    */
		// 8ms执行时间
    vector<vector<int>> res;
    vector<int> tmp;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int start){
        if(!target) {
            res.push_back(tmp);
            return;
        }
        if(start == candidates.size()) return;
        int k = start +1;
        while(k<candidates.size() && candidates[start]==candidates[k]) k++;
        dfs(candidates,target,k);
        for(int i = start;i<k;i++){
            int n = candidates[start];
            if(target>=n){
                tmp.push_back(n);
                target-=n;
                dfs(candidates,target,k);
            }
        }
        while(tmp.size() && tmp.back() == candidates[start]) tmp.pop_back();
    }
};
};