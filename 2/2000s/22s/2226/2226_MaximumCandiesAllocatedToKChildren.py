# https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:

        def isValidSplit(candies, k, currentSplitVal):
            candiesLength=len(candies)
            currentCandiesAllocated=0
            currentSplits=0
            for i in range(0, candiesLength, 1):
                if candies[i]<currentSplitVal:
                    continue
                currentCandiesAllocated+=candies[i]
                currentSplits+=candies[i]//currentSplitVal
            return currentCandiesAllocated>=k and currentSplits>=k

        def binarySearch(candies, k):
            candies.sort()
            left=1
            right=candies[len(candies)-1]
            resultantMaxCandies=0
            while(left<=right):
                mid=left+(right-left)//2
                if isValidSplit(candies, k, mid):
                    resultantMaxCandies=mid
                    left=mid+1
                else:
                    right=mid-1
            return resultantMaxCandies

        return binarySearch(candies, k)
