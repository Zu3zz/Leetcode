class Solution {
public:
	/*
	本solution执行时间为16ms
	为了逻辑清晰一些 所以讲三种情况分别作了判断 依次为行是否有重复 列是否有重复 9宫格之内是否有重复
	*/
    bool isValidSudoku(vector<vector<char>>& board) {
        int len = 9;
        // 判断行是否有效
        for(int i = 0; i < len;i++){
            if(isRowValid(i,board) == false)
                return false;
        }
        // 判断列是否有效
        for(int i = 0 ; i< len; i++){
            if(isColValid(i,board) == false)
                return false;
        }
        // 判断九宫格是否有效
        // 一次性跳过三个格子
        for(int i = 0; i<len;i+=3){
            for(int j = 0; j<len;j+=3){
                if(isBlockValid(i,j,board) == false)
                    return false;
            }
        }
        return true;
    }
    bool isRowValid(int row, vector<vector<char>>& board){
    		// 按照行每个依次判断 有"."就跳过 如果是数字 就直接添加进数组
        vector<char> temp;
        for(int i = 0; i<9;i++){
            if(board[row][i] == '.')
                continue;
            else{
                temp.push_back(board[row][i]);
            }
            // 判断是否有重复
            for(int j = 0;j<temp.size()-1;j++){
                if(temp[j] == board[row][i])
                    return false;
            }
        }
        return true;
    }
    bool isColValid(int col, vector<vector<char>>& board){
    		// 按照列每个依次判断 有"."就跳过 如果是数字 就直接添加进数组
        vector<char> temp;
        for(int i = 0; i<9;i++){
            if(board[i][col] == '.')
                continue;
            else{
                temp.push_back(board[i][col]);
            }
            // 判断是否有重复
            for(int j = 0;j<temp.size()-1;j++){
                if(temp[j] == board[i][col])
                    return false;
            }
        }
        return true;
    }
    bool isBlockValid(int row,int col,vector<vector<char>>& board){
        vector<char> temp;
        for(int i = row; i<row+3;i++){
            for(int j = col; j<col+3;j++){
                if(board[i][j] == '.')
                    continue;
                else{
                    temp.push_back(board[i][j]);
                }
                for(int k = 0;k<temp.size()-1;k++){
                    if(temp[k] == board[i][j])
                    return false;
                }
            }
        }
        return true;
    }
};