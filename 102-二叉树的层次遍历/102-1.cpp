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
此solution需要花费4ms的执行时间
一看到题目涉及到二叉树 便想到两种方法 分别是BFS和DFS
题目需要逐层输出二叉树中的每一个值 刚好跟BFS的思想一样 所以使用BFS来做
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    	  // 题目需要返回一个二维数组 二维数组中的每一个元素都是一个一维数组 其中包括了每一层的值
    	  // 所以提前申明一个二维数组res 用来保存结果
        vector<vector<int>> res;
        // 判断是否为一个空树 如果空树直接返回空二维数组即可
        if(!root) return res;
        // 申明一个队列用来存储二叉树结点值
        queue<TreeNode*> q;
        // 将根节点推入queue中
        q.push(root);
        // 同时添加一个NULL指针用来标记每一层已经走到头
        q.push(NULL);
        // 申明一个数组cur 用来存储每一层的结果 每一层存储完成之后 重置cur
        vector<int> cur;
        // cout<<q.size()<<endl;
        while(!q.empty()){
        	// 拿到此时queue中的头结点
            TreeNode *t = q.front();
            // 拿到之后直接队头元素弹出
            q.pop();
            if(t == NULL){
            	// 如果为空指针的话 说明这一层已经走完
            	// 直接将cur数组添加到二维数组res中即可 
                res.push_back(cur);
                // 将cur重置 
                cur.resize(0);
                // 如果q的size大于0 说明还没有走到最后一层 接着添加一个NULL指针
                // 用来标记下一层的结束位置
                if(q.size()>0){
                    q.push(NULL);
                }
            }
            else{
            	// 如果不为空 那么说明还有值 直接将val插入cur数组即可
                cur.push_back(t->val);
                // 同时如果节点有左子树 右子树 那么将左子树和右子树push进队中 用作下一层的遍历
                if(t->left){
                    q.push(t->left);
                }
                if(t->right){
                    q.push(t->right);
                }
            }
        }
        return res;
    }
};