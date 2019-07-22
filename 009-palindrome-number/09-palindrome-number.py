"""
Determine whether an integer is a palindrome.
Do this without extra space.
"""


class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        x = abs(x)
        l = len(str(x))
        i = 1
        while i < l / 2 + 1:
            head = ((int)(x / 10 ** (l - i))) % 10
            tail = (x % 10 ** i) if i == 1 else (int)((x % 10 ** i) / (10 ** (i - 1)))
            if head != tail:
                return False
            i = i + 1
        return True

