# https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11

class Pair:

    def __init__(self, isElementPresent, indexOfTheElement):
        self.isElementPresent=isElementPresent
        self.indexOfTheElement=indexOfTheElement


class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:

        def searchElementInArr1(arr1, valueToBeSearched):
            arr1Length=len(arr1)
            for arr1Index in range(0, arr1Length, 1):
                if arr1[arr1Index]==valueToBeSearched:
                    return Pair(True, arr1Index)
            return Pair(False, -1)

        arr1Length=len(arr1)
        arr2Length=len(arr2)
        resultantSortedArray=[]
        initialTraversalIndex=0
        for arr2Index in range(0, arr2Length, 1):
            currentElementInArr2=arr2[arr2Index]
            while(True):
                searchForCurrentElementInArr1=searchElementInArr1(arr1, currentElementInArr2)
                if searchForCurrentElementInArr1.isElementPresent==True:
                    indexOfTheFoundedElement=searchForCurrentElementInArr1.indexOfTheElement
                    arr1[indexOfTheFoundedElement]=-1
                    resultantSortedArray.append(currentElementInArr2)
                else:
                    break
        arr1.sort()
        for arr1Index in range(0, arr1Length, 1):
            if arr1[arr1Index]!=-1:
                resultantSortedArray.append(arr1[arr1Index])
        return resultantSortedArray