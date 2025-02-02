# https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/submissions/1194664530/?envType=daily-question&envId=2024-03-05

class Solution:
    def minimumLength(self, s: str) -> int:
        
        def dfs(s, left, right):
            if left>=right or s[left]!=s[right]:
                return right-left+1
            if s[left]==s[right]:
                tochk=s[left]
                while(left<=right and s[left]==tochk):
                    left+=1
                while(left<=right and s[right]==tochk):
                    right-=1
                return dfs(s, left, right)
            return right-left+1

        sz=len(s)
        left=0
        right=sz-1
        return dfs(s, left, right)