/*
https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17
*/

/**
 * @param {number[]} nums
 * @return {boolean}
 */

const Pair=class{
    constructor(currentPairLength, lastElement){
        this.currentPairLength=currentPairLength;
        this.lastElement=lastElement;
    } 
}

var divideArray = function(nums) {
    nums.sort();
    let lengthOfNums=nums.length,
        totalNumPairsFormed=lengthOfNums/2,
        lengthOfEachSubPair=lengthOfNums/totalNumPairsFormed,
        beginIndex=0;
    let prev=null;
    while(true){
        if(beginIndex>=lengthOfNums) break;
        if(prev!=null&&prev.currentPairLength==lengthOfEachSubPair){
            prev.currentPairLength=0;
            prev.lastElement=0;
            prev.currentPairLength++;
            prev.lastElement=nums[beginIndex++];
        } else{
            if(prev!=null&&prev.currentPairLength>=1){
                let toCheckElement=nums[beginIndex++];
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
};
