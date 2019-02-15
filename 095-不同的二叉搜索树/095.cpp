/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0) return res;
        return DFS(1,n);
    }
    vector<TreeNode*> DFS(int begin, int end){
        vector<TreeNode*> res;
        if(begin>end){
            res.push_back(NULL);
            return res;
        }
        for(int i = begin; i<=end;++i){
        	// 分出一个左子树 右子树 分别递归循环
            vector<TreeNode*> left = DFS(begin,i-1);
            vector<TreeNode*> right = DFS(i+1,end);
            for(auto l: left){
                for(auto r: right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};