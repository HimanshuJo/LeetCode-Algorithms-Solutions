/*
https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17
*/

class Pair{

    public int currentPairLength;
    public int lastElement;

    public Pair(int currentPairLength, int lastElement){
        this.currentPairLength=currentPairLength;
        this.lastElement=lastElement;
    }
}


class Solution {
    public boolean divideArray(int[] nums) {
        Arrays.sort(nums);
        int lengthOfNums=nums.length, 
            totalNumPairsFormed=lengthOfNums/2,
            lengthOfEachSubPair=lengthOfNums/totalNumPairsFormed,
            beginIndex=0;
        Pair prev=null;
        while(true){
            if(beginIndex>=lengthOfNums) break;
            if(prev!=null&&prev.currentPairLength==lengthOfEachSubPair){
                prev.currentPairLength=0;
                prev.lastElement=0;
                prev.currentPairLength++;
                prev.lastElement=nums[beginIndex++];
            } else{
                if(prev!=null&&prev.currentPairLength>=1){
                    int toCheckElement=nums[beginIndex++];
                    if(toCheckElement!=prev.lastElement) return false;
                    prev.currentPairLength++;
                } else{
                    prev=new Pair(0, 0);
                    prev.currentPairLength++;
                    prev.lastElement=nums[beginIndex++];
                }
            }
        }
        return true;
    }
}
