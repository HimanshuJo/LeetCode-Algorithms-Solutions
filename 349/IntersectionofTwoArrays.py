# https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        st=set()
        mp={}
        sz1=len(nums1)
        sz2=len(nums2)
        for i in range(0, sz1, 1):
            if nums1[i] not in mp:
                mp[nums1[i]]=1
            else:
                curval=mp[nums1[i]]
                mp[nums1[i]]=curval+1
        for i in range(0, sz2, 1):
            if nums2[i] in mp:
                st.add(nums2[i])
        res=[]
        for ele in st:
            res.append(ele)
        return res