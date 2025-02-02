# https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        def customFind(s, ch, idx):
            sz=len(s)
            if idx>=sz:
                return False
            for i in range(0, sz, 1):
                if i!=idx and s[i]==ch:
                    return True
            return False
        
        sz=len(s)
        for i in range(0, sz, 1):
            flag=customFind(s, s[i], i)
            if flag==False:
                return i
        return -1