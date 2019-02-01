/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
大体思路跟102-1一样 具体细节做了优化
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        TreeNode * front;
        queue<TreeNode*> q;
        q.push(root);
        // cout<<q.size()<<endl;
        while(!q.empty()){
            vector<int> cur;
            // for循环的条件是精髓 因为q被pop之后 q的size会变 所以必须用这种写法才行
            for(int i = q.size();i>0;i--){
                front = q.front();
                q.pop();
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                cur.push_back(front->val);
            }
            res.push_back(cur);
        }
        return res;
    }
};