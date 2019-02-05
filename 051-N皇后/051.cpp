class Solution {
public:
	/*
	本solution执行时间为4ms
	N皇后的主要问题就是解决放入一个皇后之后 下一层皇后应该放置的位置
	即同一竖排不可以放置 左45度 右45度均不可放置
	*/
    vector<vector<string>> solveNQueens(int n) {
        // 初始化每一层皇后是否可以放置
        vector<int> level(n,-1);
        // 用来存储N皇后的结果
        vector<vector<string>> res;
        // 使用DFS的思想进行递归
        nQueensDFS(level,res,0);
        return res;
    }
    void nQueensDFS(vector<int> &level,vector<vector<string>> &res,int curlevel){
        // 获取N皇后的大小 直到最后一层才输出
        int n = level.size();
        if(curlevel != n){
            // 每一行逐个位置依次判断是否可以将皇后放置
            for(int curpos = 0;curpos<n;curpos++){
                if(isPlaceable(level,curlevel,curpos)){
                    level[curlevel]= curpos;
                    nQueensDFS(level,res,curlevel+1);
                    level[curlevel] = -1;
                }
            }
        }
        // 说明循环已经到达了最后一层 将需要的皇后的解的形式存储进res数组里
        else{
            vector<string> temp(n,string(n,'.'));
            for(int i=0;i<n;i++){
                temp[i][level[i]] = 'Q';
            }
            res.push_back(temp);
        }
    }
    bool isPlaceable(vector<int> &level,int curlevel, int curpos){
        for(int i =0 ;i<curlevel;i++){
            if(curpos == level[i] || abs(curlevel-i) == abs(curpos - level[i])){
                return false;
            }
        }
        return true;
    }
};