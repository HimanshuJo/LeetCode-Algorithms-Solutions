/*
https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/?envType=daily-question&envId=2025-04-26
*/

/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let lengthOfNums=nums.length, lastMinIndex=-1, lastMaxIndex=-1, lastBadIndex=-1;
    let res=0;
    for(let i=0; i<lengthOfNums; ++i){
        if(nums[i]<minK||nums[i]>maxK){
            lastBadIndex=i;
        }
        if(nums[i]==minK) lastMinIndex=i;
        if(nums[i]==maxK) lastMaxIndex=i;
        let curValidIndex=Math.min(lastMinIndex, lastMaxIndex);
        if(curValidIndex>lastBadIndex){
            res+=(curValidIndex-lastBadIndex);
        }
    }
    return res;
};