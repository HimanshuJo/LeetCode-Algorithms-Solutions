# https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01

class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        res=""
        sz=len(word)
        idxtogt=0
        while(True):
            if idxtogt>=sz or word[idxtogt]==ch:
                break
            idxtogt+=1
        if idxtogt>=sz:
            return word
        for i in range(idxtogt, -1, -1):
            res+=word[i]
        if idxtogt+1<=sz-1:
            for i in range(idxtogt+1, sz, 1):
                res+=word[i]
        return res