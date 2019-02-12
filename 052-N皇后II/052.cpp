class Solution {
private:
    int count;
public:
		/*
		采用位运算进行N皇后问题的判断
		假设一个4行的棋盘如下 1010 1代表皇后可以攻击的位置 0代表安全区域 即可以放置新皇后的区域
		采用DFS的思想进行深搜 每次搜索到结果符合要求就将count++ 
		*/
    int totalNQueens(int n) {
        if(n<1) return 0;
        count = 0;
        DFS(n,0,0,0,0);
        return count;
    }
    void DFS(int n, int row, int col, int pie, int na){
        if(row >= n) {
            count++;
            return;
        }
        /*
        这一步是用来保存每一层上那些位置还可以放置皇后的
        col代表上一层垂直方向已经放置的皇后
        pie na分别代表两个斜向可以被皇后攻击到的地方
        通过或运算 可以将这些位置全部置为1 同时亦或后面这一项 保证之有需要的个数是有效的 前面的全部置为0
        */
        int bits = (~(col | pie | na) & ((1 << n) - 1));
        while(bits){
        		/*
        		把最后一位拿出来 DFS传入下一行 同时左移右移 斜向传递
        		*/
            int p = bits & (-bits);
            DFS(n,row+1,col | p, (pie | p) << 1,(na | p) >> 1);
            bits = bits & (bits - 1);
        }
    }
};