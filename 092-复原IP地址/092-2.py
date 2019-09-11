class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        res = []
        def backtrace(i, tmp, flag):
            if flag == 0 and i == n:
                res.append(tmp[:-1])
                return
            if flag < 0:
                return
            for j in range(i, i+3):
                if j < n:
                    if i == j and s[j] == "0":
                        backtrace(j+1, tmp+s[j]+".", flag-1)
                        break
                    if 0 < int(s[i:j+1]) <= 255:
                        backtrace(j+1, tmp+s[i:j+1]+".", flag-1)
        
        backtrace(0,"",4)
        return res