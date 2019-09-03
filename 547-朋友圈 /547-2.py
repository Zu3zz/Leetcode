"""
使用dfs进行优化
"""
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        visited,res,n = set(),0,len(M)
        def dfs(i):
            for j in range(len(M[i])):
                if M[i][j] and j not in visited:
                    visited.add(j)
                    dfs(j)
                
        for i in range(n):
            if i not in visited:
                dfs(i)
                res+=1
        return res
                