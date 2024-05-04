/*
https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02
*/

/**
 * @param {number[]} nums
 * @return {number}
 */

var customSearch=function(nums, val){
    let left=0, right=nums.length-1;
    while(left<=right){
        if(nums[left++]===-val) return true;
        else if(nums[right--]==-val) return true;
    }
    return false;
}

var findMaxK = function(nums) {
    nums.sort((A, B)=>(A-B));
    let sz=nums.length;
    for(let i=sz-1; i>=0; --i){
        let curr=nums[i];
        if(curr>=0){
            let flag=customSearch(nums, curr);
            if(flag===true) return curr;
        }
    }
    return -1;
};