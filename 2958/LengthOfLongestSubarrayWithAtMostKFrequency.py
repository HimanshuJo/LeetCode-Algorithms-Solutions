# https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/?envType=daily-question&envId=2024-03-28

class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        sz=len(nums)
        left=-1
        right=0
        res=0
        mp={}
        for right in range(0, sz, 1):
            if nums[right] in mp:
                mp[nums[right]]=mp[nums[right]]+1
                while(mp[nums[right]]>k):
                    left+=1
                    mp[nums[left]]=mp[nums[left]]-1
            else:
                mp[nums[right]]=1
            res=max(res, right-left)
        return res