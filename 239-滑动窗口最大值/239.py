from collections import Counter
class Solution:
	# python3可以使用collections 模块中的Counter直接对两个字符串计数比较
	# 这样省事一些 但是时间复杂度相比较cpp比较高 执行时间会达到64ms
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dict_1 = Counter(s)
        dict_2 = Counter(t)
        if(dict_1 == dict_2):
            return True
        else:
            return False