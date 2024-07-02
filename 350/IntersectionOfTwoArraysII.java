/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02
*/

class Solution {

    public static int isCurrentElementPresentInNums2(int[] nums, int currentElement){
        int lengthNums=nums.length;
        for(int i=0; i<lengthNums; ++i){
            if(nums[i]==currentElement) return i;
        }
        return -1;
    }

    public int[] intersect(int[] nums1, int[] nums2) {
        ArrayList<Integer>listOfIntersectionOfTwoArrays=new ArrayList<>();
        int lengthNums1=nums1.length;
        for(int i=0; i<lengthNums1; ++i){
            int currentElement=nums1[i], indexOfCurrentElementInNums2=isCurrentElementPresentInNums2(nums2, currentElement);
            if(indexOfCurrentElementInNums2!=-1){
                listOfIntersectionOfTwoArrays.add(currentElement);
                nums2[indexOfCurrentElementInNums2]=-1;
            }
        }
        int sizeOfIntersectionList=listOfIntersectionOfTwoArrays.size();
        int[] resultantArray=new int[sizeOfIntersectionList];
        for(int i=0; i<sizeOfIntersectionList; ++i){
            resultantArray[i]=listOfIntersectionOfTwoArrays.get(i);
        }
        return resultantArray;
    }
}