# https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10

class Solution:
    def countSubstrings(self, s: str) -> int:

        def isPalindrome(strlst):
            left=0
            right=len(strlst)-1
            while(left<=right):
                if strlst[left]!=strlst[right]:
                    return False
                left+=1
                right-=1
            return True

        sz=len(s)
        res=0
        for i in range(0, sz, 1):
            curr=[]
            for j in range(i, sz, 1):
                curr.append(s[j])
                if isPalindrome(curr):
                    res+=1
        return res