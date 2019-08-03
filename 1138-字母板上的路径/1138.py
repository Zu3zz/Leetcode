class Solution(object):
    def alphabetBoardPath(self, target):
        """
        :type target: str
        :rtype: str
        """
        # {a:[0,0],b:[0,1],c:[0,2],d:[0,3],e[0:4],f:[1:0],g[1:1]...}
        m = {c:[i/5,i%5] for i, c in enumerate("abcdefghijklmnopqrstuvwxyz")}
        x0,y0 = 0,0
        res = []
        for c in target:
            x,y = m[c]
            # z只能向上 所以先判断向左
            # 然后向上
            if y < y0: res.append('L'*(y0-y))
            if x < x0: res.append('U'*(x0-x))
            if x > x0: res.append('D'*(x-x0))
            if y > y0: res.append('R'*(y-y0))
            res.append('!')
            x0,y0 = x,y
        return "".join(res)
            