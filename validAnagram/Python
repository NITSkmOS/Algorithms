class validAnagram:
    def makeDic(self, s):
        D = {}
        for term in s:
            if term in D:
                D[term] += 1
            else:
                D[term] = 1
        return D
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        myD = self.makeDic(s)
        for term in t:
            if term not in myD:
                return False
            else:
                myD[term] -= 1
                if myD[term] < 0:
                    return False
        for char in myD:
            if myD[char] != 0:
                return False
        return True
