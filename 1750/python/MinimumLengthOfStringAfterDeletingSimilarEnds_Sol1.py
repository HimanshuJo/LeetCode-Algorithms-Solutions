# https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/submissions/1194664530/?envType=daily-question&envId=2024-03-05

class Solution:
    def minimumLength(self, s: str) -> int:
        sz=len(s)
        left=0
        right=sz-1
        while(left<right):
            curlft=s[left]
            currght=s[right]
            if curlft==currght:
                while(left<=right and s[left]==curlft):
                    left+=1
                while(left<=right and s[right]==currght):
                    right-=1
            else:
                break
        return right-left+1