/*
https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20
*/

/**
 * @param {number[]} nums
 * @return {number}
 */

var binarySearch=function(nums, val){
    let left=0, right=nums.length-1;
    while(left<=right){
        let mid=Math.floor(left+(right-left)/2);
        if(nums[mid]===val) return true;
        else if(nums[mid]>val){
            right=mid-1;
        } else left=mid+1;
    }
    return false;
};

var find=function(nums, val){
    return binarySearch(nums, val);
};

var missingNumber = function(nums) {
    nums.sort((A, B)=>(A-B));
    let sz=nums.length;
    for(let i=0; i<=sz; ++i){
        let flag=find(nums, i);
        if(flag===false) return i;
    }
    return -1;
};