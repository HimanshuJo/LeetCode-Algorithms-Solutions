/*
https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15
*/

/**
 * @param {number[]} nums
 * @return {number}
 */
var largestPerimeter = function(nums) {
    nums.sort((A, B)=>(A-B));
    let sz=nums.length;
    for(let i=sz-1; i>=0; --i){
        let curval=nums[i], cursm=0;
        for(let j=0; j<i; ++j){
            cursm+=nums[j];
        }
        if(cursm>curval&&i>=2) return cursm+curval;
    }
    return -1;
};