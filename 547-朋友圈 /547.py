"""
这是一道典型的使用并查集解决问题的方法
并查集的思路就是使用数组记录相同的cluster
这里由于使用简单的quick union会导致栈溢出
所以使用路径压缩的递归方式寻找 这样可以避免报错
"""
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        res = {}  
        n = len(M)
        f = [i for i in range(n)]
        def find(p):
            if p!=f[p]:
                f[p] = find(f[p])
            return f[p]
        
        def union(p,q):
            f[find(p)] = find(q)
        for i in range(n):
            for j in range(i+1,n):
                if M[i][j] == 1:
                    union(i,j)
        ret = 0
        for i in range(n):
            if f[i] == i:
                ret+=1
        return ret