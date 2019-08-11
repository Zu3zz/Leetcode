"""
给定一个表示分数加减运算表达式的字符串，你需要返回一个字符串形式的计算结果。 这个结果应该是不可约分的分数，即最简分数。 如果最终结果是一个整数，例如 2，你需要将它转换成分数形式，其分母为 1。所以在上述例子中, 2 应该被转换为 2/1。

输入:"-1/2+1/2"
输出: "0/1"
输入:"-1/2+1/2+1/3"
输出: "1/3"
输入:"1/3-1/2"
输出: "-1/6"
输入:"5/3+1/3"
输出: "2/1"
"""

class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        # 求最大公约数
        def gcd(a,b):
            return b if a%b==0 else gcd(b,a%b)
        # 求最小公倍数
        def lcm(a,b):
            return int(a*b/gcd(a,b))
        # 如果只有一个分数 说明没有加减法操作 直接返回原值
        if expression.count('/') == 1: return expression
        # 吧所有的减法操作都用+一个负数来实现 方便split
        expression = expression.replace('-','+-')
        tmp = expression.split('+')
        # tem_res用来存储每一个参与运算的数的分子和分母
        tmp_res = []
        for x in tmp:
            if(len(x)):
                y = x.split('/')
                tmp_res.append((int(y[0]),int(y[1])))
        fm,fz=1,0
        for x in tmp_res:
            fm=lcm(fm,x[1])
        for x in tmp_res:
            fz+=x[0]*(fm//x[1])
        if fz==0:return '0/1'
        gys=gcd(fm,abs(fz))
        return str(fz//gys)+'/'+str(fm//gys)
        