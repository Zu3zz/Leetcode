"""
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
"""
class stack:
    def __init__(self):
        self.stack = []
        self.top = -1

    def push(self, data):
        self.stack.append(data)
        self.top += 1

    def pop(self):
        data = self.stack[-1]
        self.top -= 1
        del self.stack[-1]
        return data

    def isEmpty(self):
        if (self.top == -1):
            return True
        else:
            return False


class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if (s == None or len(s) == 0):
            return False
        if (len(s) % 2 != 0):
            return False
        stk = stack()

        for i in range(len(s)):
            if (s[i] == "(" or s[i] == "[" or s[i] == "{"):
                stk.push(s[i])
            elif (s[i] == ")"):
                if (not stk.isEmpty()):
                    if (stk.pop() != "("):
                        # print(1)
                        return False
                else:
                    return False
            elif (s[i] == "]"):
                if (not stk.isEmpty()):
                    if (stk.pop() != "["):
                        # print(2)
                        return False
                else:
                    return False
            elif (s[i] == "}"):
                if (not stk.isEmpty()):
                    if (stk.pop() != "{"):
                        # print(3)
                        return False
                else:
                    return False
        if (stk.isEmpty()):
            return True
        return False
