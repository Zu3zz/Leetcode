class Solution:
    def reverseParentheses(self, s: str) -> str:
        res = ['']
        tmp = ''
        for c in s:
            if c == '(':
                res += ['']
            elif c == ')':
                res[-2] += res[-1][::-1]
                res.pop()
            else:
                res[-1] += c
        return res[0]