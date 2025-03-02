# https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        lengthOfNums1=len(nums1)
        lengthOfNums2=len(nums2)
        resultantList=[]
        idToValueMap={}
        for i in range(0, lengthOfNums1, 1):
            if nums1[i][0] in idToValueMap:
                currentValue=idToValueMap[nums1[i][0]]
                currentValue+=nums1[i][1]
                idToValueMap[nums1[i][0]]=currentValue
            else:
                idToValueMap[nums1[i][0]]=nums1[i][1]
        for i in range(0, lengthOfNums2, 1):
            if nums2[i][0] in idToValueMap:
                currentValue=idToValueMap[nums2[i][0]]
                currentValue+=nums2[i][1]
                idToValueMap[nums2[i][0]]=currentValue
            else:
                idToValueMap[nums2[i][0]]=nums2[i][1]
        for key in sorted(idToValueMap.keys()):
            currentList=[]
            currentList.append(key)
            currentList.append(idToValueMap[key])
            resultantList.append(currentList)
        return resultantList