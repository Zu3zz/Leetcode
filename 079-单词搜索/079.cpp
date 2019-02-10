static const auto __lamda = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
/*
本solution执行时间为8ms
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    		// 判断是否有为空的时候
        if(board.empty() || word.empty()) return false;
        // 获取到二维数组的行大小和列大小
        int row = board.size();
        int col = board[0].size();
        // 定义一个二维数组f 用来记录二维数组中的字母是否已经被访问过
        vector<vector<int>> f(row, vector<int>(col,0));
        // 开始逐行遍历
        for(int i = 0;i<row;++i){
            for(int j = 0 ;j<col;++j){
            		// 利用dfs 深搜的思想 每次都深搜四个方向 查看是否可以与给出的word匹配
                if(dfs(board,word,0,i,j,f)) return true;
            }
        }
        return false;
    }
    bool dfs (vector<vector<char>>& board, string& word, int size, int x, int y, vector<vector<int>>& f){
    		// 如果此时已经匹配完成的字符与所给的字符长度相同 那么说明已经顺利查完 直接返回true即可
        if(size ==  word.size()) return true;
        // 边界问题 
        if(x<0 || x>=board.size() || y<0 ||y>board[0].size()||board[x][y] != word[size]) return false;
        if(f[x][y] == 0){
        		// 只有没有走过的路径才能开始循环 经过了就置为1
            f[x][y] = 1;
            // 四个方向分别开始dfs
            if(dfs(board,word,size+1,x-1,y,f)
               || dfs(board,word,size+1,x,y+1,f)
               || dfs(board,word,size+1,x+1,y,f)
               || dfs(board,word,size+1,x,y-1,f)){
                return true;
            }
            f[x][y] = 0;
        }
        return false;
    }
};